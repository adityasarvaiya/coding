#!/bin/bash

c++ T4.cpp

if [ "$1" == "r" ]; then
    ./a.out < in1.txt > f31.txt
fi