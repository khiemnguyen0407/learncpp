#!/bin/bash

my_array=("value 1" "value 2" "value 3" "value 4")

echo ${my_array[0]}
echo ${my_array[1]}
echo ${my_array[2]}
echo ${my_array[3]}

echo "All elements in my_array"
echo ${my_array[@]}

echo "Number of elements in my_array:"
echo ${#my_array[@]}
