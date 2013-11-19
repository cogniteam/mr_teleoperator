/*
 * MrmRqt.h
 *
 *  Created on: Nov 14, 2013
 *      Author: blackpc
 */

#ifndef MRMRQT_H_
#define MRMRQT_H_

#include <iostream>
#include <set>

#include <boost/foreach.hpp>
#include <boost/date_time.hpp>
#include <boost/thread.hpp>
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int32.h>

#include <qlistview.h>
#include <qstandarditemmodel.h>

#include <rqt_gui_cpp/plugin.h>
#include <pluginlib/class_list_macros.h>

#include <mr_rqt/MrmControllerUi.h>

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

private:
	QWidget* _widget;
	Ui_MrmController _mrmControllerUi;
	ros::NodeHandle _node;
	ros::Publisher _controlledRobotPublisher;

	void wireUpEvents();
	void refreshRobots();

public slots:

	void refreshClicked();
	void controlRobotClicked();
};

} /* namespace mrm_rqt */

#endif /* MRMRQT_H_ */
