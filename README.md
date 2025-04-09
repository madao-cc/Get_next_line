# Get_next_line

> **Objective:** Develop a function that reads and returns the next line from a file descriptor.

## Table of Contents

- [Project Overview](#project-overview)
- [Key Features](#key-features)
- [Files in the Repository](#files-in-the-repository)
- [Usage](#usage)
- [Implementation Details](#implementation-details)
- [Testing](#testing)
- [Learning Outcomes](#learning-outcomes)
- [Acknowledgments](#acknowledgments)

## Project Overview

The **Get_next_line** project focuses on creating a function that reads a file line by line. This task enhances understanding of file operations in C, including opening, reading, and closing files, and managing static variables for persistent state across function calls.

## Key Features

- **Line-by-Line Reading:** Retrieves text from a file one line at a time.
- **Buffer Management:** Efficiently handles data using a buffer to accommodate varying line lengths.
- **Static Variable Usage:** Maintains state between function calls to manage data that doesn't fit into a single buffer.

## Files in the Repository

- `get_next_line.c`: Contains the main `get_next_line` function.
- `get_next_line.h`: Header file with function prototypes and necessary macros.
- `get_next_line_utils.c`: Utility functions supporting `get_next_line`.
- `Makefile`: Automates the compilation process.
- `README.md`: This documentation file.

## Usage

To integrate `get_next_line` into your project:

1. **Compilation:** Use the provided `Makefile`:
   ```bash
   make
   ```
   This generates the object files and the necessary library.

2. **Function Prototype:**
   ```c
   char *get_next_line(int fd);
   ```
   - `fd`: File descriptor of the file to be read.

3. **Example Usage:**
   ```c
   #include "get_next_line.h"
   #include <fcntl.h>
   #include <stdio.h>

   int main(void)
   {
       int fd = open("example.txt", O_RDONLY);
       char *line;

       while ((line = get_next_line(fd)) != NULL)
       {
           printf("%s", line);
           free(line);
       }
       close(fd);
       return 0;
   }
   ```

## Implementation Details

- **Buffer Size:** Defined by the macro `BUFFER_SIZE` in `get_next_line.h`. Adjust this value to optimize performance based on expected line lengths and system capabilities.

- **Static Variables:** Utilized to retain data between function calls, allowing the function to handle lines that span multiple reads.

- **Edge Cases Handled:**
  - Lines longer than the buffer size.
  - Files without newline characters.
  - Proper memory management to prevent leaks.

## Testing

To test the `get_next_line` function:

1. **Create a Test File:** Prepare a text file (`test.txt`) with various line lengths and content.

2. **Compile with a Test Program:** Use a test program (e.g., `main.c`) that calls `get_next_line` and outputs the results.

3. **Run the Test:**
   ```bash
   gcc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c -o gnl_test
   ./gnl_test
   ```

4. **Verify Output:** Ensure the output matches the content of the test file, line by line.

## Learning Outcomes

Through this project, the following concepts are reinforced:

- **File I/O Operations:** Understanding how to open, read, and close files in C.
- **Dynamic Memory Allocation:** Managing memory for buffers and ensuring no leaks occur.
- **Static Variables:** Using static variables to maintain state across function calls.
- **Buffer Management:** Efficiently handling data that may not fit into a single read operation.

## Acknowledgments

This project is part of the curriculum at 42 School, designed to deepen understanding of file handling and memory management in C.
