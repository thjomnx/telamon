#!/bin/bash

# Setup paths
workdir=$(dirname "$(readlink -f "$0")")
basedir=$(cd $workdir/..; pwd)

mainapp="$basedir/bin/telamon/telamon"
testapp="$basedir/bin/telamon-test/test"

# Change working directory
cd $workdir/..

# Clean old build remnants and targets
make distclean &> /dev/null

# Create new targets
qmake

# Build all targets
make all
