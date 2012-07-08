######################################################################
# Project build file (qmake) - create date: 26.02.2012
######################################################################

# Target settings
TEMPLATE = app
TARGET = telamon
DESTDIR = ../bin
INCLUDEPATH += .

# Qt settings
QT += network
CONFIG += qt debug warn_on

# Build settings
DESTDIR = ../bin
UI_DIR = ../build/ui
MOC_DIR = ../build/moc
RCC_DIR = ../build/rcc
OBJECTS_DIR = ../build

# Source settings
HEADERS += mainwindow.h \
           connectioneditor.h \
           remoteviewer.h \
           macroeditor.h \
           udpreceiverwidget.h \
           textmacrowidget.h \
           udpsender.h \
           udpreceiver.h

SOURCES += main.cpp \
           mainwindow.cpp \
           connectioneditor.cpp \
           remoteviewer.cpp \
           macroeditor.cpp \
           udpreceiverwidget.cpp \
           textmacrowidget.cpp \
           udpsender.cpp \
           udpreceiver.cpp

FORMS += mainwindow.ui \
         connectioneditor.ui \
         remoteviewer.ui \
         macroeditor.ui \
         udpreceiverwidget.ui \
         textmacrowidget.ui
