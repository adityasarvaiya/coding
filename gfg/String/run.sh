#!/bin/bash

c++ Stringoholics.cpp

if [ "$1" == "r" ]; then
    ./a.out < t.in 
fi