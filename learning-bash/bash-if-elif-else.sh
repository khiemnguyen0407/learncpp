#!/bin/bash

read -p "Enter a number please: " num
if [[ $num -gt 0 ]]; then
    echo "The number is positive"
elif [[ $num -lt 0 ]]; then
	echo "The number is negative"
else
	echo "The number is 0"
fi
