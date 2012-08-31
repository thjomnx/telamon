######################################################################
# Project build file (qmake) - create date: 26.02.2012
######################################################################

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
           connectioneditor.h \
           remoteviewer.h \
           macroeditor.h \
           textmacrowidget.h

SOURCES += main.cpp \
           mainwindow.cpp \
           connectioneditor.cpp \
           remoteviewer.cpp \
           macroeditor.cpp \
           textmacrowidget.cpp

FORMS += mainwindow.ui \
         connectioneditor.ui \
         remoteviewer.ui \
         macroeditor.ui \
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
