#!/bin/bash

if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <path_to_test_folder> <mode>"
    exit 1
fi

# Set the path to the folder containing the files to be tested
test_folder="$1"
mode="$2"

if [[ $mode -lt 1 || $mode -gt 5 ]]; then
	exit 1
fi

# Build using Makefile
make

# Check if make was successful
if [ $? -eq 0 ]; then
    echo "Build successful."
else
    echo "Build failed. Exiting."
    exit 1
fi

Off="\033[0m"
if [ $mode -eq 1 ]; then
	CYN="\e[0;36m"
	echo -e "${CYN}Bubble Sort${Off}"
elif [ $mode -eq 2 ]; then
	PUR="\033[0;35m"
	echo -e "${PUR}Insertion Sort${Off}"
elif [ $mode -eq 3 ]; then
	BLU="\e[0;34m"
	echo -e "${BLU}Selection Sort${Off}"
elif [ $mode -eq 4 ]; then
	YEL="\e[0;33m"
	echo -e "${YEL}Merge Sort${Off}"
elif [ $mode -eq 5 ]; then
	RED="\e[0;31m"
	echo -e "${RED}Quick Sort${Off}"
fi

# Loop through each file in the test folder
for file in "$test_folder"/*; do
    if [ -f "$file" ]; then
        echo -e "Testing $file"
        # Add your test command here, for example:
        ./sort "$file" "$mode"
    fi
done

echo "Testing complete."

# Optionally, you can clean up after testing
make fclean
