/*
 * MrmTeleoperator.cpp
 *
 *  Created on: Nov 12, 2013
 *      Author: blackpc
 */

/**
 * DEPRECATED
 */

#include <iostream>
#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Int32.h>

#include "Utilities.hpp"

using namespace std;


vector<ros::Publisher> _publishers;
ros::Subscriber _joySubscriber;
ros::Subscriber _activeRobotSubscriber;

int32_t _activeRobotNumber = 1;
double _aScale;
double _lScale;
ros::Timer _publishTimer;
bool _deadmanPressed = false;
geometry_msgs::Twist _lastVelocityMessage;
bool _enabled = false;

void joyCallback(const sensor_msgs::Joy::ConstPtr& joy)
{
	geometry_msgs::Twist vel;
	vel.angular.z = _aScale * joy->axes[3];
	vel.linear.x = _lScale * joy->axes[4];
	_deadmanPressed = joy->buttons[4];
	_lastVelocityMessage = vel;
}

void publishVelocity(const ros::TimerEvent& event) {
	if (_enabled) {
		_publishers[_activeRobotNumber - 1].publish(_lastVelocityMessage);
	}
}

void initPublishers(ros::NodeHandle& node, vector<string> topicNames) {
	for (size_t i = 0; i < topicNames.size(); i++) {
		_publishers.push_back(node.advertise<geometry_msgs::Twist>(topicNames[i], 1, false));
		ROS_INFO("Advertising topic '%s'", topicNames[i].c_str());
	}
}

void onRobotSelect(const std_msgs::Int32 robotNumber) {
	if (robotNumber.data > 0 && robotNumber.data <= _publishers.size()) {
		ROS_INFO("Controlled robot set to #%i", robotNumber.data);
		_activeRobotNumber = robotNumber.data;
		_enabled = true;
	}

	if (robotNumber.data == 0) {
		ROS_INFO("Controlled robot set to none", robotNumber.data);
		_activeRobotNumber = 0;
		_enabled = false;
	}
}

int main(int argc, char **argv) {
	ros::init(argc, argv, "mr_teleoperator");

	ros::NodeHandle node("~");

	string joyTopic;
	node.param<string>("joy_topic", joyTopic, "/joy");

	int robotsCount;
	node.param<int>("robots_count", robotsCount, 10);

	string robotNsFormat;
	node.param<string>("robot_ns_format", robotNsFormat, "/pioneer_{robotId}");

	string velocityTopic;
	node.param<string>("velocity_topic", velocityTopic, "cmd_vel");

	node.param("scale_angular", _aScale, 0.9);
	node.param("scale_linear" , _lScale, 2.0);

	vector<string> topics = Utilities::getTopicNames(robotsCount, robotNsFormat, velocityTopic);
	initPublishers(node, topics);

	_joySubscriber = node.subscribe<sensor_msgs::Joy>(joyTopic, 10, joyCallback);
	_activeRobotSubscriber = node.subscribe<std_msgs::Int32>("select_robot", 1, onRobotSelect);

	_publishTimer = node.createTimer(ros::Duration(0.1), publishVelocity);

	ros::spin();
}



