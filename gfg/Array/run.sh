#!/bin/bash

g++ 29_Inversion_of_array.cpp

if [ "$1" == "r" ]
then 
    ./a.out < t.in
fi

exit 0
