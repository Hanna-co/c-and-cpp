# C Polynomial Calculator

A C programming project that performs polynomial operations using linked lists and dynamic memory allocation.

## Overview
This project reads polynomial terms from a text file, stores them in linked lists, combines like terms, sorts terms by exponent, and prints formatted polynomial expressions.

The project demonstrates core computer science concepts including data structures, memory management, modular programming, and file handling in C.

## Features
- Reads polynomial terms from a text file
- Stores terms using linked lists
- Combines like terms
- Sorts polynomial terms by exponent
- Prints formatted polynomial expressions
- Uses dynamic memory allocation
- Modular `.c` and `.h` file structure

## Technologies Used
- C Programming
- Linked Lists
- Dynamic Memory Allocation
- File Handling
- Structs
- Modular Programming

## Project Structure
- `project.c` — Main program logic
- `polynomial.c / polynomial.h` — Polynomial operations
- `term.c / term.h` — Term formatting and structures
- `basiclist.c / basiclist.h` — Linked list implementation
- `terms.txt` — Input polynomial terms
- `makefile` — Build automation

## **Example Output:** Polynomial of degree 4: 2x^4 + 5x^3 + 3x + 2

## **How to Compile:** `gcc project.c polynomial.c term.c basiclist.c -o polynomial`

## **How to Run:** `./polynomial`

## **Author:** Hanna Amare

