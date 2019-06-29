#!/bin/bash

c++ 1_min_operation.cpp

if [ "$1" == "r" ]; then
    ./a.out < t.in 
fi