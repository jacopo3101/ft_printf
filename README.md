# ft_printf

## Score
![project score](/assets/score.png)

## Introduction
This project involves the reimplementation of the printf() function in C, offering a practical exploration of variadic functions.

### Prototype
```c
int ft_printf(const char *, ...);

```

### Allowed function
| Function     | Description                             |
|--------------|-----------------------------------------|
| `malloc  `     | Allocate memory                         |
| `free    `     | Free allocated memory                   |
| `write   `     | Write to a file descriptor              |
| `va_start`     | Initialize a va_list                   |
| `va_arg  `     | Access variable arguments in va_list    |
| `va_copy `     | Copy a va_list                          |
| `va_end  `     | End using variable arguments in va_list |


## Mandatory part
Here is the list of implemented conversions:

- `%c` Prints a single character.
- `%s` Prints a string (as defined by the common C convention).
- `%p` The void * pointer argument has to be printed in hexadecimal format.
- `%d` Prints a decimal (base 10) number.
- `%i` Prints an integer in base 10.
- `%u` Prints an unsigned decimal (base 10) number.
- `%x` Prints a number in hexadecimal (base 16) lowercase format.
- `%X` Prints a number in hexadecimal (base 16) uppercase format.
- `%%` Prints a percent sign.

## Bonus part
| Flag | Description                              |
|------|------------------------------------------|
| #    | Alternate form for certain conversions   |
| +    | Always include a sign (+ or -) for numerical output |
| ' '  | If no sign is going to be written, a blank space is inserted before the value. |