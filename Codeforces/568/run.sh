#!/bin/bash

c++ Extra_Element.cpp

if [ "$1" == "r" ]; then
    ./a.out < t.in 
fi