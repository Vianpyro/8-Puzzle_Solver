# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.30.3)

# Define the project and its name
project(main)

# Add all source files to the SOURCES variable
file(GLOB SOURCES "*.c")

# Add an executable target
add_executable(my_executable ${SOURCES})
