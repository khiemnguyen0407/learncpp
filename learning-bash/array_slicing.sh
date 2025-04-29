#!/bin/bash

# While bash does not support true array slicing, we can achieve similar results
# using a combination of array index and string slicing:

array=("A" "B" "C" "D" "E" "F")

echo "Print entire array"
echo "${array[@]}"	# output: A B C D E F

# Access a single element
echo "Access a single element"
echo "${array[1]}"	# output: B

# Print a range of elements (requires Bash 4.0+)
echo "${array[@]:1:3}"	# output: B C D

# Print from an index to the end
echo "${array[@]:3}"	# output: D E
