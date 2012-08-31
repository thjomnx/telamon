######################################################################
# Project build file (qmake) - create date: 26.02.2012
######################################################################

# Qt settings
CONFIG  += qtestlib
INCLUDEPATH += ../src/utils ../build/telamon-test/moc

# Build settings
DESTDIR = ../bin/telamon-test
MOC_DIR = ../build/telamon-test/moc
OBJECTS_DIR = ../build/telamon-test

# Procedure sources
SOURCES = procedures/hostaddressvalidatortest.cpp

# Unit sources
HEADERS += ../src/utils/hostaddressvalidator.h

SOURCES += ../src/utils/hostaddressvalidator.cpp
