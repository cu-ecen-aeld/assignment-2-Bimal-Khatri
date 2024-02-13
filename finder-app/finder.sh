#!/bin/bash

# Check if the correct number of arguments is provided
if [ $# -ne 2 ]; then
    echo "Usage: $0 <filesdir> <searchstr>"
    exit 1
fi

filesdir="$1"
searchstr="$2"

# Check if the directory exists
if [ ! -d "$filesdir" ]; then
    echo "Directory does not exist: $filesdir"
    exit 1
fi

# Search for the string within files in the directory
result=$(grep -r "$searchstr" "$filesdir")

# Count the number of files and matching lines
num_files=$(echo "$result" | grep -c '^')
num_lines=$(echo "$result" | wc -l)

echo "The number of files are $num_files and the number of matching lines are $num_lines"
