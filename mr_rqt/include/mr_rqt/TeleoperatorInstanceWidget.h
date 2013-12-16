/*
 * Filename: TeleoperatorInstanceWidget.h
 *   Author: Igor Makhtes
 *     Date: Dec 5, 2013
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

#ifndef TELEOPERATORINSTANCEWIDGET_H_
#define TELEOPERATORINSTANCEWIDGET_H_

#include <iostream>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/foreach.hpp>
#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <std_msgs/String.h>

#include <QtGui/QDockWidget>

#include <geometry_msgs/Twist.h>
#include <mr_rqt/VelocityWidget.h>
#include <mr_rqt/TeleoperatorInstance.h>
#include <mr_rqt/KeyboardTeleop.h>

using namespace std;

class TeleoperatorInstanceWidget : public QWidget {

Q_OBJECT

public:

    enum InputMethod {
        Joystick = 0, Keyboard = 1, Mouse = 2
    };

    TeleoperatorInstanceWidget(
            ros::NodeHandle& nodeHandle, InputMethod inputMethod,
            int robotNumber, string velocityTopic, string feedbackVelocityFeedback)
            : _nodeHandle(nodeHandle) {
        _robotNumber = robotNumber;
        _linearVelocity = 0;
        _angularVelocity = 0;
        _inputMethod = inputMethod;
        _closed = false;

        connect(this, SIGNAL(redrawSignal()), this, SLOT(redraw()),
                Qt::QueuedConnection);

        initTopics(inputMethod, feedbackVelocityFeedback, velocityTopic);

        _widget.setupUi(this);
        _velocityWidget = new mr_rqt::VelocityWidget(
                _widget.joystickContainer);
        _velocityWidget->setMinimumSize(200, 200);
        _velocityWidget->setMaximumSize(200, 200);
        _velocityWidget->setCallback(
                boost::bind(&TeleoperatorInstanceWidget::uiJoystickCallback, this,
                        _1, _2));
        _widget.titleLabel->setText(
                QString::fromStdString(
                        "Robot #" + boost::lexical_cast<string>(robotNumber)
                                + " [" + inputMethodStr(inputMethod) + "]"));

        _keyboardWidget = new mr_rqt::KeyboardTeleop();
        _keyboardWidget->setCallback(
                boost::bind(&TeleoperatorInstanceWidget::keyboardCallback, this,
                        _1, _2));
        _widget.keyboardInput->installEventFilter(_keyboardWidget);

        initJoystick(inputMethod);

    }

    virtual ~TeleoperatorInstanceWidget() {

        _closed = true;

    }

public slots:

    /**
     * Executed on UI Thread
     */
    void redraw() {
        _widget.lcdLinearVelocity->display(_linearVelocity);
        _widget.lcdAngularVelocity->display(_angularVelocity);
    }

signals:

    void redrawSignal();

private:

    int _robotNumber;
    InputMethod _inputMethod;

    ros::NodeHandle& _nodeHandle;

    ros::Publisher _publisher;
    ros::Subscriber _subscriber;

    Ui_teleoperatorInstance _widget;
    mr_rqt::VelocityWidget* _velocityWidget;
    mr_rqt::KeyboardTeleop* _keyboardWidget;

    double _linearVelocity;
    double _angularVelocity;

    volatile bool _closed;


    void initJoystick(InputMethod method) {
        switch (method) {
            case TeleoperatorInstanceWidget::Joystick:
                _velocityWidget->disableMouseControl();
                _widget.keyboardInput->hide();
                break;
            case TeleoperatorInstanceWidget::Mouse:
                _velocityWidget->enableMouseControl();
                _widget.keyboardInput->hide();
                break;
            case TeleoperatorInstanceWidget::Keyboard:
                _velocityWidget->disableMouseControl();
                _widget.keyboardInput->show();
                break;
        }
    }

    void initTopics(InputMethod method, string feedbackTopicName, string velocityTopic) {
        _publisher = _nodeHandle.advertise<geometry_msgs::Twist>(velocityTopic, 20,
                false);
        _subscriber = _nodeHandle.subscribe(feedbackTopicName, 50,
                &TeleoperatorInstanceWidget::onVelocityMessage, this);
    }

    void uiJoystickCallback(double linearPercent, double angularPercent) {

        if (_closed)
            return;

        geometry_msgs::Twist cmdVel;
        cmdVel.linear.x = linearPercent / 50.0;
        cmdVel.angular.z = angularPercent / 50.0;
        _publisher.publish(cmdVel);
    }

    void keyboardCallback(double linear, double angular) {
        if (_closed)
            return;

        if (_inputMethod != TeleoperatorInstanceWidget::Keyboard)
            return;

        geometry_msgs::Twist cmdVel;
        cmdVel.linear.x = linear;
        cmdVel.angular.z = angular;
        _publisher.publish(cmdVel);
    }

    void onVelocityMessage(const geometry_msgs::Twist::Ptr velocityMessage) {

        if (_closed)
            return;

        double linear = velocityMessage->linear.x;
        double angular = velocityMessage->angular.z;

        _velocityWidget->setVelocity(linear, angular);

        _linearVelocity = linear;
        _angularVelocity = angular;

        if (_inputMethod == TeleoperatorInstanceWidget::Joystick)
            _publisher.publish(velocityMessage);

        emit redrawSignal();
    }

    string inputMethodStr(InputMethod method) {
        switch (method) {
            case TeleoperatorInstanceWidget::Joystick:
                return "Joystick";
            case TeleoperatorInstanceWidget::Mouse:
                return "Mouse";
            case TeleoperatorInstanceWidget::Keyboard:
                return "Keyboard";
            default:
                return "None";
        }
    }
};

#endif /* TELEOPERATORINSTANCEWIDGET_H_ */
