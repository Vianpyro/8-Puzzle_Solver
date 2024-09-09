# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.30.3)

# Define the project and its name
project(main)

# Recursively add all source files to the SOURCES variable, but exclude the CMake files directories
file(GLOB_RECURSE SOURCES
    "*.c"
    # Exclude CMake files directories
    "${CMAKE_BINARY_DIR}/**"
)

# Add an executable target
add_executable(my_executable ${SOURCES})
