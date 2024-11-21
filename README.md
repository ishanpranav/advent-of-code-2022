# Advent of Code 2022

This is a collection of solutions to the
[Advent of Code 2022](https://adventofcode.com/2022) programming problems
implemented in the C programming language. We am focusing on efficient solutions
and including formal pseudocode with each solution.

## Authors

Ishan Pranav and Iris Lim

## Usage

These programs are cross-platform, having been tested on Windows and Linux
operating systems.

**Important:** Do not use Windows-style line endings (`CR LF`, i.e. `\r\n`).
Only use Unix-style line endings (`LF`, i.e. `\n`).

**Important:** There is no error-checking. An invalid input usually results in a
segmentation violation.

**Important:** I have tested each program on the example test cases and two
puzzle input files - not a large sample size! I have avoided assumptions about
the input, sometimes even at the cost of performance. However, to avoid memory
allocation, all buffers have fixed sizes. Ensure that all buffers (see `#define`
statements) have sufficient capacity before running. Not doing so could result
in a stack smashing, segmentation violation, or worse.

## Omissions

* We have decided to omit Day 5(a) and (b) on principle.
