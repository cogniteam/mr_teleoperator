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
	: _outputReady(false), _widget(NULL), _velocityWidget(NULL), _spinThread(boost::bind(&MrRqt::spin, this))
{
	_setInputPublisher		= _node.advertise<std_msgs::Int32>("/velocity_dispatcher/set_input", 1, false);
	_setOutputPublisher 	= _node.advertise<std_msgs::Int32>("/velocity_dispatcher/set_output", 1, false);

	_cmdvelSubscriber 		= _node.subscribe("/pioneer_1/cmd_vel", 1, &MrRqt::onVelocityMessage, this);
}

MrRqt::~MrRqt()
{
//	delete _widget;
}

void MrRqt::wireUpEvents()
{
	connect(_mrmControllerUi.selectOutputButton,	SIGNAL(clicked()), this, SLOT(selectOutputClicked()));
	connect(_mrmControllerUi.selectInputButton,		SIGNAL(clicked()), this, SLOT(selectInputClicked()));
}

void MrRqt::refreshInputOutput(map<string, string>& inputs, vector<string> outputs)
{
	/**
	 * Inputs
	 */
	_mrmControllerUi.inputMethods->clear();
	pair<string, string> input;
	foreach(input, inputs) {
		_mrmControllerUi.inputMethods->addItem(QString::fromStdString(
				input.first + " [" + input.second + "]"));

		if (input.first == "Mouse") {
			ROS_INFO("Mouse velocity topic = %s", input.second.c_str());
			_mouseVelocityPublisher = _node.advertise<geometry_msgs::Twist>(input.second, 1, false);
		}

		if (input.first == "Keyboard") {
			ROS_INFO("Keyboard velocity topic = %s", input.second.c_str());
			_keyboardVelocityPublisher = _node.advertise<geometry_msgs::Twist>(input.second, 1, false);
		}
	}

	/**
	 * Outputs
	 */
	_mrmControllerUi.controllableRobots->clear();
	_mrmControllerUi.controllableRobots->addItem(QString::fromStdString("None"));

	int robotId = 1;
	foreach(string velocityTopic, outputs) {
		_mrmControllerUi.controllableRobots->addItem(QString::fromStdString(
				"Robot #" + boost::lexical_cast<string>(robotId++) + " [" + velocityTopic + "]"));
	}

	if (robotId > 1)
		_mrmControllerUi.controllableRobots->setCurrentIndex(1);

	_outputReady = true;
}

bool MrRqt::setupInputOuput(ros::NodeHandle& node)
{

	if (node.hasParam("/mr_teleoperator/input_topics"))
		node.getParam("/mr_teleoperator/input_topics", _inputTopics);
	else {
		ROS_ERROR("No input topics provided");
		return false;
	}

	if (node.hasParam("/mr_teleoperator/output_topics"))
		node.getParam("/mr_teleoperator/output_topics", _outputTopics);
	else {
		ROS_ERROR("No output topics provided");
		return false;
	}

	_currentInput 	= 0;
	_currentOutput 	= 0;

	refreshInputOutput(_inputTopics, _outputTopics);
	refreshConfiguration();

	return true;
}

void MrRqt::initPlugin(qt_gui_cpp::PluginContext& context)
{
	QStringList argv = context.argv();
	_widget = new QWidget();
	_mrmControllerUi.setupUi(_widget);

	_velocityWidget = new VelocityWidget(_widget);
	_velocityWidget->setObjectName(QString::fromUtf8("canvas"));
	_velocityWidget->setMinimumSize(QSize(200, 200));
	_velocityWidget->setMaximumSize(QSize(200, 200));
	_velocityWidget->setCallback(boost::bind(&MrRqt::publishMouseVelocity, this, _1, _2));
	_mrmControllerUi.gridLayout->addWidget(_velocityWidget, 3, 0, 1, 1, Qt::AlignHCenter);

	context.addWidget(_widget);

	setupInputOuput(_node);

	_mrmControllerUi.keyboardTeleop->installEventFilter(&_keyboardTeleop);
	_keyboardTeleop.setCallback(boost::bind(&MrRqt::publishKeyboardVelocity, this, _1, _2));

	_mrmControllerUi.keyboardTeleop->setVisible(false);

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

void MrRqt::refreshConfiguration()
{
	if (_currentOutput >= 0) {
		_mrmControllerUi.lblCurrentRobot->setText(QString::fromStdString("#" + boost::lexical_cast<string>(_currentOutput + 1)));
		_mrmControllerUi.lblCurrentTopic->setText(QString::fromStdString(_outputTopics[_currentOutput]));
	}
	else {
		_mrmControllerUi.lblCurrentRobot->setText(QString::fromStdString("None"));
		_mrmControllerUi.lblCurrentTopic->setText(QString::fromStdString("None"));
	}

	_mrmControllerUi.lblCurrentInput->setText(_mrmControllerUi.inputMethods->currentText());

}

void MrRqt::publishMouseVelocity(double linearPercent, double angularPercent)
{
	geometry_msgs::Twist message;

	message.linear.x = (linearPercent / 100.0) * 3;
	message.angular.z = (angularPercent / 100.0) * 3;

	if (_outputReady)
		_mouseVelocityPublisher.publish(message);
}

void MrRqt::publishKeyboardVelocity(double linear, double angular)
{
	geometry_msgs::Twist message;

	message.linear.x = linear;
	message.angular.z = angular;

	if (_outputReady)
		_keyboardVelocityPublisher.publish(message);
}

void MrRqt::onVelocityMessage(const geometry_msgs::Twist::Ptr velocity)
{
	if (_velocityWidget == NULL)
		return;

	_velocityWidget->setVelocity(velocity->linear.x, velocity->angular.z);
	_mrmControllerUi.lcdLinear->display(velocity->linear.x);
	_mrmControllerUi.lcdAngular->display(velocity->angular.z);


}

void MrRqt::spin()
{
	ros::spin();
}

void MrRqt::selectInputClicked()
{
	if (!_outputReady)
		return;

	string inputMethod = _mrmControllerUi.inputMethods->currentText().toStdString();


	if (boost::starts_with(inputMethod, "Mouse")) {
		_velocityWidget->enableMouseControl();
	} else
		_velocityWidget->disableMouseControl();


	if (boost::starts_with(inputMethod, "Keyboard")) {
		_mrmControllerUi.keyboardTeleop->setVisible(true);
	} else {
		_mrmControllerUi.keyboardTeleop->setVisible(false);
	}

	std_msgs::Int32 selectedInput;
	selectedInput.data = _mrmControllerUi.inputMethods->currentIndex() + 1;
	_setInputPublisher.publish(selectedInput);

	_currentInput = selectedInput.data - 1;

	_velocityWidget->resetLimits();

	refreshConfiguration();
}

void MrRqt::selectOutputClicked()
{
	if (!_outputReady)
		return;

	std_msgs::Int32 selectedOutput;
	selectedOutput.data = _mrmControllerUi.controllableRobots->currentIndex();
	_setOutputPublisher.publish(selectedOutput);

	_cmdvelSubscriber.shutdown();

	if (selectedOutput.data - 1 >= 0)
		_cmdvelSubscriber = _node.subscribe(_outputTopics[selectedOutput.data - 1], 1, &MrRqt::onVelocityMessage, this);

	_currentOutput = selectedOutput.data - 1;

	refreshConfiguration();
}

} /* namespace mrm_rqt */




PLUGINLIB_EXPORT_CLASS(mr_rqt::MrRqt, rqt_gui_cpp::Plugin)
