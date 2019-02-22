#!/bin/bash

g++ 50_Three_Great_Candidates.cpp

if [ "$1" == "r" ]
then 
    ./a.out < t.in
fi

exit 0
