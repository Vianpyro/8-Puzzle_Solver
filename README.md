# 8-Puzzle Solver

This project is an implementation of an 8-puzzle solver in C.

## Table of Contents

- [Introduction](#introduction)
- [Getting Started](#getting-started)
- [Brute Force Approach](#brute-force-approach)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The 8-puzzle is a classic problem in computer science and artificial intelligence, where the goal is to move tiles on a 3x3 grid to achieve a desired end configuration. This repository contains an 8-puzzle solver.

## Getting Started

### Prerequisites

To compile and run this project, you need:

- A C compiler (e.g., `gcc`)

### Installation

Clone the repository:

```bash
git clone https://github.com/Vianpyro/8-Puzzle_Solver.git
cd 8-Puzzle_Solver
```

Build the project:

Linux (GCC):

```bash
gcc ./*.c ./solve/*.c -o 8-puzzle
```

macOS (Clang):

```bash
clang ./*.c ./solve/*.c -o 8-puzzle
```

Windows (CMake):

_Make sure [CMake file](CMakeLists.txt) is in the folder_

```bash
mkdir build
cd build
cmake ..
make
```

## Brute Force Approach

The brute force method explores all possible moves from a given configuration to find a solution. This approach is straightforward but may not be efficient for puzzles that are far from the solution.

- Exhaustive search of all possible configurations
- Guaranteed to find a solution (if one exists)

## Usage

Open a terminal and run the binary file.

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request for any improvements or new features.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
