#!/bin/bash

x=1
z=2

for x in `ls`; do
    if [ ${#x} -gt 10 ]; then
        if [ -f ${z:0:4}0.png ]; then
            mv "${z:0:4}0.png" "${z:0:4}0 $x" 
        fi

        if [ -f ${z:0:5}0.png ]; then
            mv "${z:0:5}0.png" "${z:0:5}0 $x" 
        fi
        
        echo $x
    fi
    z=$x
done

exit 0
