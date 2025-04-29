#!/bin/bash

if [[ $EUID == 0 ]]; then
	echo "Please do not run as root"
	exit
fi
