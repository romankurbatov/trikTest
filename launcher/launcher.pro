# Copyright 2013 Roman Kurbatov
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

TEMPLATE = app

QT += core gui xml network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG(debug, debug | release) {
	CONFIGURATION = debug
	CONFIGURATION_SUFFIX = d
} else {
	CONFIGURATION = release
	CONFIGURATION_SUFFIX =
}

TARGET = trikTest$$CONFIGURATION_SUFFIX

DESTDIR = ../build/$$CONFIGURATION

OBJECTS_DIR = .build/$$CONFIGURATION/obj
MOC_DIR = .build/$$CONFIGURATION/moc

INCLUDEPATH += ../common

LIBS += -ltrikControl \
	-L../build/$$CONFIGURATION \
	-ltrikTestCommon

SOURCES += \
	main.cpp \
	trikTestApplication.cpp \
	configurer.cpp \
	launcher.cpp \
	logPrinter.cpp

HEADERS  += \
	trikTestApplication.h \
	configurer.h \
	launcher.h \
	logPrinter.h

OTHER_FILES += \
	trikTest.xml

QMAKE_POST_LINK = "cp -f trikTest.xml $$DESTDIR"
