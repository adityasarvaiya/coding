#!/bin/bash

c++ MaxSubArray.cpp

if [ "$1" == "r" ]; then
    ./a.out < t5.txt
fi