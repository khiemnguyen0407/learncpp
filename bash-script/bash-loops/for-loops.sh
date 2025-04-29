#!/bin/bash

users="nguyen lu trong khiem"
for user in ${users}
do
    echo "${user}"
done

for num in {1..10}
do
    printf ${num}
    printf " "
done
printf "\n"

for i in {1..9}
do
    for j in {1..9}
    do
        printf "${i} * ${j}"
        printf " = "
        printf $(($i*$j))
        printf "  "
    done
    printf "\n"
done
