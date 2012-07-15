######################################################################
# Project build file (qmake) - create date: 26.02.2012
######################################################################

# Target settings
TARGET = telamon
TEMPLATE = app
DESTDIR = ../bin
INCLUDEPATH += . udp

# Qt settings
QT += core gui network
CONFIG += qt debug warn_on

# Build settings
DESTDIR = ../bin
UI_DIR = ../build/ui
MOC_DIR = ../build/moc
RCC_DIR = ../build/rcc
OBJECTS_DIR = ../build

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

# UDP sources
HEADERS += udp/udpreceiverwidget.h \
           udp/udpsender.h \
           udp/udpreceiver.h

SOURCES += udp/udpreceiverwidget.cpp \
           udp/udpsender.cpp \
           udp/udpreceiver.cpp

FORMS += udp/udpreceiverwidget.ui