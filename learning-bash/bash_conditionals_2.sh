#!/bin/bash

admin="cafesua"

read -p "Enter your name? " username

# Check if the username provided is the admin

if [[ "${username}" == "${admin}" ]] ; then
	echo "You are the admin user"
else
	echo "You are NOT the admin user!"
fi 
