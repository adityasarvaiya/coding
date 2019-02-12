#!/bin/bash

g++ 23_Find_all_pairs_with_a_given_sum.cpp

if [ "$1" == "r" ]
then 
    ./a.out < t.in
fi

exit 0