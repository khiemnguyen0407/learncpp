#!/bin/bash

counter=1
while [[ $counter -le 10 ]]
do
    printf $counter
    printf "  "
    ((counter++))
done

read -p "What is your name? " name
while [[ -z ${name} ]]
do
    echo "Your name cannot be blank. Please enter a valid name!"
    read -p "Enter your name again? " name
done

echo "Hi there ${name}"
