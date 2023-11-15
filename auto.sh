#!/bin/bash

if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <path_to_test_folder> <mode>"
    exit 1
fi

# Set the path to the folder containing the files to be tested
test_folder="$1"
mode="$2"
S
# Build using Makefile
make

# Check if make was successful
if [ $? -eq 0 ]; then
    echo "Build successful."
else
    echo "Build failed. Exiting."
    exit 1
fi

# Loop through each file in the test folder
for file in "$test_folder"/*; do
    if [ -f "$file" ]; then
        echo "Testing $file"
        # Add your test command here, for example:
        ./sort "$file" "$mode"
    fi
done

echo "Testing complete."

# Optionally, you can clean up after testing
make fclean
