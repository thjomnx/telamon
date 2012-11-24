#
# This file is part of 'telamon'.
#
#   'telamon' is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    'telamon' is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with 'telamon'. If not, see <http://www.gnu.org/licenses/>.
#

#
# Project build file (qmake) for 'telamon' main sources
#

# Target settings
TARGET = telamon
TEMPLATE = app
DESTDIR = ../bin
INCLUDEPATH += . udp utils

# Qt settings
QT += core gui network
CONFIG += qt debug warn_on

# Build settings
DESTDIR = ../bin/telamon
UI_DIR = ../build/telamon/ui
MOC_DIR = ../build/telamon/moc
RCC_DIR = ../build/telamon/rcc
OBJECTS_DIR = ../build/telamon

# Main sources
HEADERS += mainwindow.h \
           localendpointpanel.h \
           remoteendpointpanel.h \
           datasinkpanel.h \
           macropanel.h \
           textmacrowidget.h

SOURCES += main.cpp \
           mainwindow.cpp \
           localendpointpanel.cpp \
           remoteendpointpanel.cpp \
           datasinkpanel.cpp \
           macropanel.cpp \
           textmacrowidget.cpp

FORMS += mainwindow.ui \
         localendpointpanel.ui \
         remoteendpointpanel.ui \
         datasinkpanel.ui \
         macropanel.ui \
         textmacrowidget.ui

# Utility sources
HEADERS += utils/hostaddressvalidator.h

SOURCES += utils/hostaddressvalidator.cpp

# UDP sources
HEADERS += udp/udpreceiverconfigdialog.h \
           udp/udpreceiverwidget.h \
           udp/udpsender.h \
           udp/udpreceiver.h

SOURCES += udp/udpreceiverconfigdialog.cpp \
           udp/udpreceiverwidget.cpp \
           udp/udpsender.cpp \
           udp/udpreceiver.cpp

FORMS += udp/udpreceiverconfigdialog.ui \
         udp/udpreceiverwidget.ui
