# Large Integer Calculator Using Linked Lists

## Overview

This project implements a **Large Integer Calculator** in C that performs arithmetic operations on integers of arbitrary length using linked list data structures.

It supports **addition**, **subtraction**, **multiplication**, and **division** for large integers by representing each number as a **doubly linked list of digits**.

The program reads numbers from a file, stores them in a **singly linked list**, and allows the user to perform operations on the numbers through a command-line interface.

## Features

- Read large integers from a file (`file.txt`).
- Store each number as a doubly linked list of digits (for easy arithmetic operations).
- Perform:
  - **Addition**
  - **Subtraction**
  - **Multiplication**
  - **Division (quotient and remainder)**
- Store multiple numbers in a singly linked list.
- Print results to the console and also output them to a file (`output.txt`).
- Support for positive and negative numbers.

## Data Structures Used

- **Doubly Linked List (Int)**: Each digit of the number is stored as a node for easy backward and forward traversal.
- **Singly Linked List (List)**: Stores multiple large integers with metadata such as index and sign.

## File Format

Input file (`file.txt`) should contain numbers like:
+12345 -67890 +999999999


Each number should be on a separate line.

## Menu Options

When running the program, the following menu will be displayed:
1: Print Numbers 2: ADD 3: Subtract 4: Multiply 5: Divide 6: Exit


## Core Functions

### Arithmetic Operations
- `Add(Int x, Int y, int signX, int signY)`
- `Subtract(Int x, Int y, int signX, int signY)`
- `Multiply(Int x, Int y, int signX, int signY)`
- `Divide(Int x, Int y, Int r, int signX, int signY)`

### Linked List Functions
- **Doubly Linked List**:
  - `CreateInt()`
  - `InsertDigitAtEnd()`
  - `InsertDigitAtBeginning()`
  - `PrintFromEnd()`
  - `PrintFromEndAtFile()`
  - `CompareValue()`
  - `MakeCopy()`
  - `RemoveDigit()`
  
- **Singly Linked List**:
  - `CreateList()`
  - `InsertIntAtEnd()`
  - `PrintAllNumbers()`
  - `FindInt()`

### File Handling
- `ReadNumbers()`: Reads numbers from `file.txt` and stores them in a singly linked list.
- Results are automatically printed to both **console** and **output.txt**.

## Compilation & Running

To compile:

```bash
gcc your_code_filename.c -o large_integer_calculator


