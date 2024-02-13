#!/bin/bash

	if [ $# -ne 2 ]; then
		echo "Both of the arguments not assigned"
		exit 1
	writefile=$1
	writestr=$2
#!/bin/bash

# Check if the writefile and writestr arguments are specified
if [ $# -ne 2 ]; then
    echo "Error: Two arguments are required."
    exit 1
fi

writefile="$1"
writestr="$2"

# Create the directory path if it doesn't exist
mkdir -p "$(dirname "$writefile")"

# Write the content to the file
echo "$writestr" > "$writefile"

# Check if the file was created successfully
if [ $? -ne 0 ]; then
    echo "Error: Failed to create the file."
    exit 1
fi

exit 0
