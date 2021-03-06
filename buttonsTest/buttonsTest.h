/* Copyright 2013 Roman Kurbatov
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License. */

#pragma once

#include <QtGui/QWidget>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QKeyEvent>
#include <QtCore/QSet>
#include <QtCore/QMap>
#include <QtCore/QTimer>
#include <QtCore/QEventLoop>

#include "testInterface.h"

//namespace trikTest
//{

class ButtonsTest
		: public QWidget
		, public TestInterface
{
	Q_OBJECT
	Q_INTERFACES(TestInterface)

public:
	TestInterface::Result run(trikControl::Brick &, QStringList &log);

private:
	QLabel mTopLabel;
	QLabel mBottomLabel;
	QVBoxLayout mLayout;

	QStringList *mLog;
	int mDelay;
	QSet<int> mPressedButtons;
	QSet<int> mAllButtons;
	QMap<int, QString> mButtonsNames;
	QTimer mTimer;
	QEventLoop mEventLoop;
	Result mResult;

protected:
	void keyPressEvent(QKeyEvent *event);

private slots:
	void timeout();
};

//}
