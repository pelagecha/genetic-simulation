#!/bin/bash

# Run make and check if it succeeds
if make; then
    echo "Build succeeded. Running the program..."
    ./runnable
else
    echo "Build failed. Fix the issues and try again."
    exit 1
fi