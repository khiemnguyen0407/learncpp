#!/bin/bash

# Script that returns the current server status

server_name=$(hostname)
echo ${server_name}

function memory_check() {
    echo ""
        echo "The current memory usage on ${server_name} is: "
        free -h
        echo ""
}

# Call the function
memory_check
