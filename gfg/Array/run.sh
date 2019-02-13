#!/bin/bash

g++ 25_Element_left_smaller_right_greater.cpp

if [ "$1" == "r" ]
then 
    ./a.out < t.in
fi

exit 0
