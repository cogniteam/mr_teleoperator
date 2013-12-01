/**
 * Filename: KeyboardTeleop.h
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

#ifndef KEYBOARDTELEOP_H_
#define KEYBOARDTELEOP_H_

#include <iostream>

#include <boost/thread.hpp>

#include <ros/ros.h>

#include <QWidget>
#include <QEvent>
#include <QKeyEvent>

using namespace std;

typedef boost::function<void (double, double)> VelocityCallback;

class KeyboardTeleop : public QObject {
Q_OBJECT

public:

	KeyboardTeleop()
		: _updateThread(boost::bind(&KeyboardTeleop::updateThread, this))
	{
		_linear = 0;
		_angular = 0;
		_angularDown = false;
		_linearDown = false;
	}

	virtual ~KeyboardTeleop() { }

	void setCallback(VelocityCallback callback) {
		_callback = callback;
	}

	bool eventFilter(QObject* obj, QEvent *event)
	{
		if (event->type() == QEvent::KeyPress)
		{
			QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);

			switch (keyEvent->key()) {
				case Qt::Key_Left:
					_angularDown = true;
					_angularDirectionSign = 1;
					break;
				case Qt::Key_Right:
					_angularDown = true;
					_angularDirectionSign = -1;
					break;
				case Qt::Key_Up:
					_linearDown = true;
					_linearDirectionSign = 1;
					break;
				case Qt::Key_Down:
					_linearDown = true;
					_linearDirectionSign = -1;
					break;
				default:
					break;
			}



			return true;
		}

		if (event->type() == QEvent::KeyRelease)
		{
			QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);

			switch (keyEvent->key()) {
				case Qt::Key_Left:
				case Qt::Key_Right:
					_angularDown = false;
					break;
				case Qt::Key_Up:
				case Qt::Key_Down:
					_linearDown = false;
					break;
			}

			return true;
		}

		return false;
	}

private:

	boost::thread _updateThread;
	double _linear;
	double _angular;
	volatile bool _linearDown;
	volatile bool _angularDown;
	int _linearDirectionSign;
	int _angularDirectionSign;
	VelocityCallback _callback;

	void updateThread() {
		while (ros::ok()) {

			double linearStep = 0.2;
			double angularStep = 0.2;

			double decayFactor = 0.7;

			if (_linearDown) {
				_linear += linearStep * _linearDirectionSign;
			} else {
				_linear *= decayFactor;

				if (fabs(_linear) < 0.001)
					_linear = 0;
			}

			if (_angularDown) {
				_angular += angularStep * _angularDirectionSign;
			} else {
				_angular *= decayFactor;

				if (fabs(_angular) < 0.001)
					_angular = 0;
			}

			_linear  = fmax(fmin(2.0, _linear), -2.0);
			_angular = fmax(fmin(2.0, _angular), -2.0);

//			ROS_WARN("Linear = %f, Angular = %f", _linear, _angular);

			if (!_callback.empty())
				_callback(_linear, _angular);

			boost::this_thread::sleep(boost::posix_time::milliseconds(50));
		}
	}


};



#endif /* KEYBOARDTELEOP_H_ */
