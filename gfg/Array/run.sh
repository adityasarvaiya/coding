#!/bin/bash

g++ 10_Pythagorean_Triplet.cpp

if [ "$1" == "r" ]
then 
    ./a.out < t.in
fi

exit 0
