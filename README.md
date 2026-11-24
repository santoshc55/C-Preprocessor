# C Preprocessor

## Project Description

The C Preprocessor is a basic implementation of a preprocessor using the C programming language. It performs preprocessing operations on a given C source file and generates an output file with the `.i` extension.

The project is developed using **Modular Programming in C**.

## Features

- **File Inclusion:** Handles basic header file inclusion.
- **Comment Removal:** Removes single-line (`//`) and multi-line (`/* */`) comments.
- **Macro Handling:** Supports object-like macros.
- **Function-Like Macros:** Supports basic macros with one or two parameters.
- **Output Generation:** Generates a preprocessed `.i` file.
- **Command-Line Arguments:** Accepts the input filename through command-line arguments.

## Technologies Used

- C Programming
- GCC Compiler
- Linux (Ubuntu)
- GNU Make
- Git and GitHub

## Project Structure

```text
C-Preprocessor/
│
├── main.c
├── preprocessor.h
├── header.h
├── comment_removal.c
├── file_inclusion.c
├── macro_handler.c
├── Makefile
├── input.c
├── input.i
└── .gitignore
```

## Compilation

Compile the project using the Makefile:

```bash
make
```

## Execution

Run the executable by providing the input C filename:

```bash
./mypreprocessor input.c
```

The preprocessed output will be generated as:

```text
input.i
```

## Sample Macros

```c
#define PI 3.14
#define SQUARE(x) ((x) * (x))
#define ADD(a,b) ((a) + (b))
```

## Sample Output

```c
int a = 3.14;
int b = ((5) * (5));
int c = ((10) + (20));
```

## Clean Generated Files

To remove object files, the executable, and generated `.i` files:

```bash
make clean
```

## Learning Outcomes

- Understanding the basic working of a C preprocessor.
- Working with file handling in C.
- Understanding macros and preprocessing operations.
- Implementing modular programming.
- Using Makefile for project compilation.
- Managing projects using Git and GitHub.

## Author

**Santosh Mahadev Chougule**

## Note

This project is a basic educational implementation of a C preprocessor. It supports selected preprocessing operations and does not implement all features of the standard C preprocessor.
