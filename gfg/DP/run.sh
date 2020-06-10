#!/bin/bash

c++ 3_matrix_multiplication.cpp

if [ "$1" == "r" ]; then
    ./a.out < t.in 
fi