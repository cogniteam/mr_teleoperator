/**
 * Filename: VelocityWidget.h
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

#ifndef VELOCITYWIDGET_H_
#define VELOCITYWIDGET_H_

#include <iostream>
#include <math.h>
#include <ros/ros.h>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>

using namespace std;

typedef boost::function<void (double, double)> VelocityCallback;

namespace mr_rqt {

class VelocityWidget : public QWidget {

Q_OBJECT

public:
	VelocityWidget(QWidget* parent)
		: QWidget(parent),
		  _linear(0),
		  _angular(0),
		  _maxLinear(1),
		  _maxAngular(1),
		  _linearPercent(0),
		  _angularPercent(0),
		  _minAngular(-1),
		  _minLinear(-1),
		  _visibleLinear(0),
		  _visibleAngular(0),
		  _mouseEnabled(false),
		  _feedbackEnabled(true),
		  _mouseDown(false),
		  _zeroVelocityCounter(0),
		  _inputTicks(0),
		  _updateThread(boost::bind(&VelocityWidget::updateThread, this))
	{

		connect(this, SIGNAL(redrawSignal()), this, SLOT(redraw()), Qt::QueuedConnection);
	}

	~VelocityWidget() {
		_updateThread.interrupt();
		_updateThread.join();
	}

	void resetLimits() {
		_maxLinear = 0.1;
		_maxAngular = 0.1;
	}

	void setLinear(double linear) {

		if (_mouseEnabled && !_feedbackEnabled)
			return;

		if (linear > _maxLinear)
			_maxLinear = (linear);

		if (linear < _minLinear)
			_minLinear = linear;

		_linear = linear;

		if (linear >= 0)
			_linearPercent = _linear / _maxLinear * 100.0;
		else
			_linearPercent = -_linear / _minLinear * 100.0;
	}

	void setAngular(double angular) {

		if (_mouseEnabled && !_feedbackEnabled)
			return;

		if (angular > _maxAngular)
			_maxAngular = (angular);

		if (angular < _minAngular)
			_minAngular = angular;

		_angular = angular;

		if (angular >= 0)
			_angularPercent = _angular / _maxAngular * 100.0;
		else
			_angularPercent = -_angular / _minAngular * 100.0;
	}

	void setVelocity(double linear, double angular) {

		if (!_feedbackEnabled)
			return;

		setLinear(linear);
		setAngular(angular);

//		cout << "Setting l/a: " << _linearPercent << ", " << _angularPercent << endl;
	}

	void setCallback(VelocityCallback callback) {
		_callback = callback;
	}

	void enableMouseControl() {
		_mouseEnabled = true;
	}

	void disableMouseControl() {
		_mouseEnabled = false;
	}

public slots:

	void redraw() {
		update();
	}

signals:

	void redrawSignal();

private:

	volatile double _linear;
	volatile double _angular;

	volatile double _maxLinear;
	volatile double _minLinear;
	volatile double _maxAngular;
	volatile double _minAngular;

	volatile double _linearPercent;
	volatile double _angularPercent;

	volatile double _visibleLinear;
	volatile double _visibleAngular;

	bool _mouseEnabled;
	bool _feedbackEnabled;
	bool _mouseDown;
	int _zeroVelocityCounter;
	volatile long _inputTicks;

	VelocityCallback _callback;

	boost::thread _updateThread;

	void updateThread() {

		while(ros::ok() && !_updateThread.interruption_requested()) {

//			cout << _linearPercent << ", " << _angularPercent << endl;

			_visibleLinear += (_linearPercent - _visibleLinear)/ 2.0;
			_visibleAngular += (_angularPercent - _visibleAngular) / 2.0;


			if (fabs(_visibleLinear) < 0.0001)
				_visibleLinear = 0;

			if (fabs(_visibleAngular) < 0.0001)
				_visibleAngular = 0;

			emit redrawSignal();

			if (!_mouseDown &&_inputTicks++ > 60)
				_feedbackEnabled = true;
			else
				_feedbackEnabled = false;

			boost::this_thread::sleep(boost::posix_time::milliseconds(1000.0 / 60.0));
		}
	}

	void limitVector(double& x, double& y, double maxRadius) {
		if (sqrt(x * x + y * y) > maxRadius) {
			double angle = atan2(y, x);
			x = cos(angle) * maxRadius;
			y = sin(angle) * maxRadius;
		}
	}

	void drawBackground(QPainter& p, int width, int height) {
		QBrush brush(QColor::fromRgb(255, 255, 255, 255));
		p.setBrush(brush);

		p.fillRect(0, 0, width, height, brush);
	}

	void drawBorder(QPainter& p, int width, int height) {
		QPen pen(QColor::fromRgb(100, 100, 100, 0));
		p.setPen(pen);

		// Horizontal
		p.drawLine(0, 0, width, 0);
		p.drawLine(0, height - 1, width, height - 1);

		// Vertical
		p.drawLine(0, 0, 0, height);
		p.drawLine(width - 1, 0, width - 1, height);
	}

	void drawAxis(QPainter& p, int width, int height) {
		QPen pen(QColor::fromRgb(0, 0, 0, 30));
		pen.setDashOffset(3);

		p.setPen(pen);

		// Horizontal
		p.drawLine(0, height / 2, width, height / 2);

		// Vertical
		p.drawLine(width / 2, 0, width / 2, height);
	}

	void drawCircles(QPainter& p, int width, int height) {
		QLinearGradient grad(0, 0, width, height);
		grad.setColorAt(1.0, QColor::fromRgb(180, 180, 180, 255));
		grad.setColorAt(0.0, QColor::fromRgb(220, 220, 220, 255));

		QPen pen(QColor::fromRgb(50, 50, 50, 255));
		QBrush brush(grad);
		brush.setStyle(Qt::LinearGradientPattern);
		p.setBrush(brush);
		p.setPen(pen);

		p.drawEllipse(0, 0, width - 1, height - 1);


		grad.setColorAt(0.0, QColor::fromRgb(180, 180, 180, 255));
		grad.setColorAt(1.0, QColor::fromRgb(220, 220, 220, 255));
		brush = QBrush(grad);

		p.setPen(Qt::NoPen);
		p.setBrush(brush);

		p.drawEllipse(20, 20, width - 1 - 20 * 2, height - 1 - 20 * 2);
	}

	void drawPointer(QPainter& p, int x, int y, int width, int height, int size) {

		int circleWidth = size * width / 100;
		int circleHeight = size * height / 100;

		int circleX = x * width / 200 + width / 2;
		int circleY = y * height / 200 + height / 2;

		circleX = circleX - circleWidth / 2;
		circleY = circleY - circleHeight / 2;


		QLinearGradient gradLine(width / 2, height / 2, circleX + circleWidth / 2, circleY + circleHeight / 2);
		gradLine.setColorAt(0.0, QColor(30, 30, 30));
		gradLine.setColorAt(0.5, QColor(100, 100, 100));
		gradLine.setColorAt(1.0, QColor(0, 0, 0));
		p.setPen(QPen(QBrush(gradLine), size / 1.1, Qt::SolidLine, Qt::RoundCap, Qt::BevelJoin));
		p.drawLine(width / 2, height / 2, circleX + circleWidth / 2, circleY + circleHeight / 2);


		QLinearGradient grad(circleX, circleY, circleX + circleWidth, circleY + circleHeight);
		grad.setColorAt(0.0, QColor::fromRgb(220, 0, 0, 255));
		grad.setColorAt(1.0, QColor::fromRgb(100, 0, 0, 255));
		QBrush brush(grad);

		p.setPen(Qt::NoPen);
		p.setBrush(brush);

		p.drawEllipse(circleX, circleY, circleWidth, circleHeight);


		grad.setColorAt(1.0, QColor::fromRgb(220, 0, 0, 255));
		grad.setColorAt(0.0, QColor::fromRgb(100, 0, 0, 255));
		brush = QBrush(grad);

		p.setPen(Qt::NoPen);
		p.setBrush(brush);

		p.drawEllipse(circleX + 5, circleY + 5, circleWidth - 10, circleHeight - 10);
	}

	void drawJoystick(int linearPercent, int angularPercent) {
		QPainter painter(this);

		double w = width();
		double h = height();

		double linear = -linearPercent;
		double angular = -angularPercent;

		limitVector(linear, angular, 70);

		drawCircles(painter, w, h);
		drawPointer(painter, angular, linear, w, h, 30);
	}

	void paintEvent(QPaintEvent *e)
	{
		drawJoystick(_visibleLinear, _visibleAngular);
	}

	void mousePressEvent(QMouseEvent* e) {
		_mouseDown = true;
		_inputTicks = 0;

		if (!_mouseEnabled)
			return;

		mouseMoveEvent(e);
	}

	void mouseMoveEvent(QMouseEvent* e) {

		_inputTicks = 0;

		if (!_mouseEnabled)
			return;

		_linearPercent = (-e->pos().y() + width() / 2);
		_angularPercent = (-e->pos().x() + width() / 2);

		if (!_callback.empty())
			_callback(_linearPercent, _angularPercent);
	}

	void mouseReleaseEvent(QMouseEvent* e) {

		_mouseDown = false;
		_inputTicks = 0;

		if (!_mouseEnabled)
			return;

		_linearPercent = (0);
		_angularPercent = (0);

		if (!_callback.empty())
			_callback(_linearPercent, _angularPercent);
	}

	void keyPressEvent(QKeyEvent* e) {
//		cout << "Key pressed = " << e->key() << endl;
	}
};

}

#endif /* VELOCITYWIDGET_H_ */
