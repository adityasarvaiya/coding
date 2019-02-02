#!/bin/bash

g++ 6_Minimum_Platforms.cpp

if [ "$1" == "r" ]
then 
    ./a.out < t.in
fi

exit 0