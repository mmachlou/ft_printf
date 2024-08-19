# ft_printf

## Overview

`ft_printf` is a custom implementation of the standard `printf` function in C, created as part of the 42 curriculum. This project demonstrates my ability to work with variadic functions, handle formatted output, and manage memory effectively. 

## Features

- **Supported Conversion Specifiers**:
  - **Character**: `%c`
  - **String**: `%s`
  - **Pointer**: `%p`
  - **Integer**: `%d`, `%i`
  - **Unsigned Integer**: `%u`
  - **Hexadecimal**: `%x`, `%X`
  - **Percent Sign**: `%%`

- **Flags, Width, and Precision Handling**:
  - **Flags**: `-`, `0`, `.` for precision.
  - **Width**: Handles minimum field width.
  - **Precision**: Controls the number of digits in output.

- **Error Management**:
  - Robust handling of edge cases and invalid input.

## Installation

To use `ft_printf` in your project:

1. Clone this repository:
   ```bash
   git clone https://github.com/mmachlou/ft_printf.git
   ```

2. Compile the library:
   ```bash
   make
   ```

3. Include `ft_printf.h` in your source files and link against `libftprintf.a`:

```c
#include "ft_printf.h"

int main(void) {
    ft_printf("Hello, %s!\n", "world");
    return 0;
}
```

4. Compile your project:

```bash
gcc -Wall -Wextra -Werror -o my_program my_program.c -L. -lftprintf
```

## Usage

You can now use `ft_printf` just like the standard `printf` function but with your custom implementation.

## Testing

Thoroughly test the library by passing various formats and flags to ensure correct functionality.
