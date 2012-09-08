#!/bin/bash

# Setup paths
workdir=$(dirname "$(readlink -f "$0")")
basedir=$(cd $workdir/..; pwd)

mainapp="$basedir/bin/telamon/telamon"
testapp="$basedir/bin/telamon-test/test"

# Start and quit main application
$mainapp &
sleep 3
kill $!

# Execute all tests
$testapp
