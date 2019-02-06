#!/bin/bash

g++ 14_Maximum_Tip_Calculator.cpp

if [ "$1" == "r" ]
then 
    ./a.out < t.in
fi

exit 0