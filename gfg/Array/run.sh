#!/bin/bash

g++ 7_Maximum_index.cpp

if [ "$1" == "r" ]
then 
    ./a.out < t.in
fi

exit 0