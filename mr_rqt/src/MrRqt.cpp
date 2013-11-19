/*
 * MrmRqt.cpp
 *
 *  Created on: Nov 14, 2013
 *      Author: blackpc
 */

#include <mr_rqt/MrRqt.h>

namespace mr_rqt
{

MrRqt::MrRqt()
	: _widget(NULL)
{
	_controlledRobotPublisher		= _node.advertise<std_msgs::Int32>("/mr_teleoperator/select_robot", 1, false);
}

MrRqt::~MrRqt()
{
	delete _widget;
}

void MrRqt::wireUpEvents()
{
	connect(_mrmControllerUi.controlRobot,			SIGNAL(clicked()), this, SLOT(controlRobotClicked()));
}

void MrRqt::refreshClicked()
{
	refreshRobots();
}

void MrRqt::refreshRobots()
{
	int robotsCount;
	_node.param<int>("/robots_count", robotsCount, 0);

	int selectedIndex = _mrmControllerUi.controllableRobots->currentIndex();
	_mrmControllerUi.controllableRobots->clear();

	_mrmControllerUi.controllableRobots->addItem(QString::fromStdString("None"));

	for (int i = 0; i < robotsCount; i++) {
		_mrmControllerUi.controllableRobots->addItem(QString::fromStdString("Robot #" + boost::lexical_cast<string>(i + 1)));
	}

	_mrmControllerUi.controllableRobots->setCurrentIndex(selectedIndex < 0 ? 0 : selectedIndex);
}


void MrRqt::initPlugin(qt_gui_cpp::PluginContext& context)
{
	QStringList argv = context.argv();
	_widget = new QWidget();
	_mrmControllerUi.setupUi(_widget);
	context.addWidget(_widget);

	refreshRobots();

	wireUpEvents();
}

void MrRqt::shutdownPlugin()
{
}

void MrRqt::saveSettings(qt_gui_cpp::Settings& plugin_settings,
		qt_gui_cpp::Settings& instance_settings) const
{
}

void MrRqt::restoreSettings(
		const qt_gui_cpp::Settings& plugin_settings,
		const qt_gui_cpp::Settings& instance_settings)
{
}

void MrRqt::controlRobotClicked()
{
	std_msgs::Int32 selectedRobot;
	selectedRobot.data = _mrmControllerUi.controllableRobots->currentIndex();
	_controlledRobotPublisher.publish(selectedRobot);
}

} /* namespace mrm_rqt */




PLUGINLIB_EXPORT_CLASS(mr_rqt::MrRqt, rqt_gui_cpp::Plugin)
