#!/bin/bash

for (( a = 1; a < 10; a++ ))
do
    echo "Inner loop: a = $a"
    for (( b = 1; b < 100; b++ ))
    do
        if [[ $b -gt 5 ]]
        then
            break 2
        fi
        echo "Inner loop: b = $b"
    done
done

echo "================="

for (( a = 1; a < 4; a++ ))
do
    echo "Inner loop: a = $a"
    for (( b = 1; b < 100; b++ ))
    do
        if [[ $b -gt 3 ]]
        then
            break
        fi
        printf "\tInner loop: b = $b\n"
    done
done
