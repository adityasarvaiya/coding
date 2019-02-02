#!/bin/bash

g++ 2_Subarray_given_sum.cpp

if [ "$1" == "r" ]
then 
    ./a.out < t.in
fi

exit 0