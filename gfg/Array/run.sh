#!/bin/bash

g++ 4_missing_num_in_array.cpp

if [ "$1" == "r" ]
then 
    ./a.out < t.in
fi

exit 0