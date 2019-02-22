#!/bin/bash

g++ Find_duplicates.cpp

if [ "$1" == "r" ]
then 
    ./a.out < t.in
fi

exit 0
