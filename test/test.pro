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
# Project build file (qmake) for 'telamon' testing sources
#

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
