#!/bin/bash

c++ Kth_largest_element.cpp

if [ "$1" == "r" ]; then
    ./a.out < t.in 
fi