# printf

## Overview

In this project we learn what are variadic functions and how to implement them.
The task is to get behind the `printf()` C function, dissect it and write one of your own from scratch.
The only difference is that our printf doesn't implement tghe original buffer management and doesn't work with all the original flags.
The function is compiled to a library which we can use in other projects.

## Usage

1. Clone the repository in your project's directory.
2. Include `ft_printf/ft_printf.h` in your header.
3. Either compile your library or add a dependency in your Makefile.
4. Compile your code with `-I./ft_printf/libftprintf.a`

The library can be compiled either mannually or using a Makefile.\
The Makefile rules are as follows:

| Rule | Despription |
| ---- | ----------- |
| ALL | Compiles the library with the printf that has mandatory and bonus flags using GCC. |
| BONUS | Compiles the library the same way 'ALL' does. |
| CLEAN | Removes object files leaving only the library present. |
| FCLEAN | Removes both the library and object files. |
| RE | Recompiles the library using **CLEAN** and **ALL** Makefile rules |

## Mandatory

| Flag | Description |
| -------- | ----------- |
| %c | Prints a single character. |
| %s | Prints a string (as defined by the common C convention). |
| %p | The void * pointer argument has to be printed in hexadecimal format. |
| %d | Prints a decimal (base 10) number. |
| %i | Prints an integer in base 10. |
| %u | Prints an unsigned decimal (base 10) number. |
| %x | Prints a number in hexadecimal (base 16) lowercase format. |
| %X | Prints a number in hexadecimal (base 16) uppercase format. |
| %% | Prints a percent sign. |

## Bonus

| Flag | Description |
| -------- | ----------- |
| - | Specifies left adjustment of the output in the indicated field. |
| 0 | Indicates that zero-padding should be used rather than blank-padding.  A ' - ' overrides a ' 0 ' if both are used. |
| . | An optional period, ‘ . ’, followed by an optional digit string giving a precision which specifies the number of digits to appear after the decimal point, for the maximum number of bytes to be printed from a string. If the digit string is missing, the precision is treated as zero. |
| # | Specifies that the value should be printed in an 'alternate form'. For c, d, s and u formats, this option has no effect. For the x (X) format, a non-zero result has the string 0x (0X) prepended to it. |
| ' ' | Specifies that a blank should be left before a positive number for a signed format.  A ' + ' overrides a space if both are used. |
| + | Specifies that there should always be a sign placed before the number when using signed formats. |
