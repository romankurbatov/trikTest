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

#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtCore/QHash>
#include <trikControl/brick.h>

#include "testInterface.h"
#include "configurer.h"

class PwmTest
		: public QObject
		, public TestInterface
{
	Q_OBJECT
	Q_INTERFACES(TestInterface)

public:
	TestInterface::Result run(trikControl::Brick &mBrick, QStringList &mLog);

	struct GeneratorFiles {
		QString requestFilePath;
		QString runFilePath;
		QString frequencyFilePath;
		QString dutyFilePath;
	};

private:
	trikControl::Brick *mBrick;
	QStringList *mLog;
	QList<Configurer::Stage> mStages;

	QList<Configurer::Value> mValues;
	TestInterface::Result result;

	QHash<QString, GeneratorFiles> mGeneratorFiles;

	void performStage(Configurer::Stage const &stage);
};
