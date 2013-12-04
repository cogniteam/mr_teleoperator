/**
 * Filename: MrRqt.h
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

#ifndef MRMRQT_H_
#define MRMRQT_H_

#include <iostream>
#include <set>

#include <boost/foreach.hpp>
#include <boost/date_time.hpp>
#include <boost/thread.hpp>
#include <boost/algorithm/string.hpp>

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int32.h>
#include <geometry_msgs/Twist.h>

#include <QListView>
#include <QPainter>
#include <QStandardItemModel>

#include <rqt_gui_cpp/plugin.h>
#include <pluginlib/class_list_macros.h>

#include <mr_rqt/MrmControllerUi.h>
#include <mr_rqt/VelocityWidget.h>
#include <mr_rqt/KeyboardTeleop.h>

using namespace std;

namespace mr_rqt
{

class MrRqt : public rqt_gui_cpp::Plugin
{
Q_OBJECT

public:
	MrRqt();
	virtual ~MrRqt();

	virtual void initPlugin(qt_gui_cpp::PluginContext& context);
	virtual void shutdownPlugin();
	virtual void saveSettings(qt_gui_cpp::Settings& plugin_settings,
			qt_gui_cpp::Settings& instance_settings) const;
	virtual void restoreSettings(const qt_gui_cpp::Settings& plugin_settings,
			const qt_gui_cpp::Settings& instance_settings);

public slots:

	void selectOutputClicked();
	void selectInputClicked();

private:
	bool _outputReady;

	boost::thread _spinThread;
	QWidget* _widget;
	VelocityWidget* _velocityWidget;
	Ui_MrmController _mrmControllerUi;

	map<string, string> _inputTopics;
	vector<string> _outputTopics;

	ros::NodeHandle _node;
	ros::Publisher _setInputPublisher;
	ros::Publisher _setOutputPublisher;
	ros::Publisher _mouseVelocityPublisher;
	ros::Publisher _keyboardVelocityPublisher;
	ros::Subscriber _cmdvelSubscriber;

	KeyboardTeleop _keyboardTeleop;


	int _currentInput;
	int _currentOutput;

	void wireUpEvents();
	void refreshInputOutput(map<string, string>& inputs, vector<string> outputs);
	bool setupInputOuput(ros::NodeHandle& node);
	void refreshConfiguration();
	void spin();

	void publishMouseVelocity(double, double);
	void publishKeyboardVelocity(double, double);

	void onVelocityMessage(const geometry_msgs::Twist::Ptr velocity);

};

} /* namespace mrm_rqt */

#endif /* MRMRQT_H_ */
