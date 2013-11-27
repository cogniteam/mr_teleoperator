/**
 * Filename: VelocityDispatcher.cpp
 *   Author: Igor Makhtes, Cogniteam Ltd.
 *     Date: Nov 26, 2013
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2013 Cogniteam Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <iostream>
#include <boost/foreach.hpp>
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Int32.h>

using namespace std;
using namespace ros;

#define foreach BOOST_FOREACH

/*************************************************************************************************
*** Parameters
**************************************************************************************************/

int _currentInput;
int _currentOutput;

vector<Subscriber> _inputs;
vector<Publisher>  _outputs;

Subscriber _setInputSubscriber;
Subscriber _setOutputSubscriber;

Publisher _currentInputPublisher;
Publisher _currentOutputPublisher;

Timer _velocityPublishTimer;
Timer _statusPublishTimer;

geometry_msgs::Twist _currentVelocity;

/*************************************************************************************************
*** Callbacks
**************************************************************************************************/

void onSetInputMessage(const std_msgs::Int32::ConstPtr inputIdMessage) {
	if (inputIdMessage->data >= 1 && inputIdMessage->data <= _inputs.size()) {
		_currentOutput = inputIdMessage->data - 1;
		ROS_INFO("Current input changed to '#%i' ['%s']", inputIdMessage->data, _inputs[_currentOutput].getTopic().c_str());
	}
}

void onSetOutputMessage(const std_msgs::Int32::ConstPtr outputIdMessage) {
	if (outputIdMessage->data >= 1 && outputIdMessage->data <= _outputs.size()) {
		_currentOutput = outputIdMessage->data - 1;
		ROS_INFO("Current output changed to '#%i' ['%s']", outputIdMessage->data, _outputs[_currentOutput].getTopic().c_str());
	}
}

void onInputVelocityMessage(const geometry_msgs::Twist::ConstPtr velocityMessage, int inputId) {
	if (inputId == _currentInput + 1)
		_currentVelocity = *velocityMessage;
}

/*************************************************************************************************
*** Functions
**************************************************************************************************/

void publishStatus(TimerEvent timerEvent) {
	std_msgs::Int32 intMessage;

	intMessage.data = _currentInput + 1;
	_currentInputPublisher.publish(intMessage);

	intMessage.data = _currentOutput + 1;
	_currentOutputPublisher.publish(intMessage);
}

void publishVelocity(TimerEvent timerEvent) {
	_outputs[_currentOutput].publish(_currentVelocity);
}

void createSubscribersAndPublishers(NodeHandle& node, map<string, string>& inputs, vector<string>& outputs) {
	/**
	 * Inputs
	 */
	int inputId = 1;
	ROS_INFO("[Preparing inputs]");
	pair<string, string> input;
	foreach (input, inputs) {
		ROS_INFO(" - Setting up input topic #%i: %s", inputId, input.second.c_str());

		_inputs.push_back(node.subscribe<geometry_msgs::Twist>
			(input.second, 100, boost::bind(onInputVelocityMessage, _1, inputId++)));
	}

	/**
	 * Outputs
	 */
	int outputId = 1;
	ROS_INFO("[Preparing outputs]");
	foreach (string output, outputs) {
		ROS_INFO(" - Setting up output topic #%i: %s", outputId++, output.c_str());

		_outputs.push_back(node.advertise<geometry_msgs::Twist>(output, 100, false));
	}

	/**
	 * Control
	 */
	_setInputSubscriber = node.subscribe("/velocity_dispatcher/set_input", 1, onSetInputMessage);
	_setOutputSubscriber = node.subscribe("/velocity_dispatcher/set_output", 1, onSetOutputMessage);

	/**
	 * Status
	 */
	_currentInputPublisher = node.advertise<std_msgs::Int32>("/velocity_dispatcher/current_input", 1, true);
	_currentOutputPublisher = node.advertise<std_msgs::Int32>("/velocity_dispatcher/current_output", 1, true);

	/**
	 * Timers
	 */
	_velocityPublishTimer = node.createTimer(Duration(0.1), boost::bind(publishVelocity, _1));
	_statusPublishTimer = node.createTimer(Duration(1), boost::bind(publishStatus, _1));
}

bool setupInputOutput(NodeHandle& node) {

	map<string, string> inputTopics;
	vector<string> outputTopics;

	if (node.hasParam("/mr_teleoperator/input_topics"))
		node.getParam("/mr_teleoperator/input_topics", inputTopics);
	else {
		ROS_ERROR("No input topics provided");
		return false;
	}

	if (node.hasParam("/mr_teleoperator/output_topics"))
		node.getParam("/mr_teleoperator/output_topics", outputTopics);
	else {
		ROS_ERROR("No output topics provided");
		return false;
	}

	_currentInput 	= 0;
	_currentOutput 	= 0;

	createSubscribersAndPublishers(node, inputTopics, outputTopics);

	return true;

}

/*************************************************************************************************
*** THIS IS MAAAAAAAAAAAAAAAAAAAAAAAIN!!!
**************************************************************************************************/

int main(int argc, char **argv) {
	init(argc, argv, "velocity_dispatcher");

	NodeHandle node;

	if (!setupInputOutput(node))
		return 1;

	spin();
	return 0;
}


