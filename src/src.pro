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
           macroeditor.h \
           textmacrowidget.h \
           udptestlistener.h \
           udptestclient.h

SOURCES += main.cpp \
           mainwindow.cpp \
           macroeditor.cpp \
           textmacrowidget.cpp \
           udptestlistener.cpp \
           udptestclient.cpp

FORMS += mainwindow.ui \
         macroeditor.ui \
         textmacrowidget.ui
