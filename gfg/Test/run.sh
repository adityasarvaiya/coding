#!/bin/bash

c++ test.cpp

if [ "$1" == "r" ]; then
    ./a.out < t.in 
fi