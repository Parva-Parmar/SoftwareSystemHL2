#!/bin/bash

# Hardcoded folder path (set this to your directory)
FOLDER="/media/deku/Data/HL2/"

# Script's own absolute path (so it won't delete itself)
SCRIPT_PATH="$(realpath "$0")"

# Check if folder exists
if [ ! -d "$FOLDER" ]; then
    echo "Error: $FOLDER is not a valid directory."
    exit 1
fi

# Find all executable files, but exclude:
#   - this script itself
#   - *.c files
#   - *.txt files
find "$FOLDER" -type f -executable \
    ! -samefile "$SCRIPT_PATH" \
    ! -name "*.c" \
    ! -name "*.txt" \
    -delete

echo "Deleted all executables in $FOLDER except this script, .c files, and .txt files."
