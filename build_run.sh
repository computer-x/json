#!/bin/bash

#JSON=/data/chenxu/some_test/json/jsoncpp
JSON=$(realpath jsoncpp)

JSONLIB=$JSON/lib
JSONINC=$JSON/include

rm test

g++ -o test main.cc -I$JSONINC -L$JSONLIB -ljsoncpp

./test
