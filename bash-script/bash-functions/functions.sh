#!/bin/bash

function hello() {
    echo "Hello world Function!"
}

hello

#######################################
# Description: Hello function
# Globals:
#   None
# Arguments:
#   Single input argument
# Outputs:
#   Value of input argument
# Returns:
#   0 if successful, non-zero on error.
#######################################

function hello_arg() {
    echo "Hello $1!"
}

hello_arg "Khiem Nguyen"
