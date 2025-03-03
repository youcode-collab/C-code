# C-code

## Cello.c look-alike library for youcode students

### Introduction

This library is designed to help youcode students understand and implement Cello-like functionality in their C programs. It provides a set of tools and examples to get you started quickly.

### Installation

To use this library, simply clone the repository and include the necessary files in your project.

```sh
git clone https://github.com/yourusername/cello-lookalike.git
```

### Usage

Include the header files in your C program:

```c
#include "lib/Var.h"
#include "lib/Arrays.h"
#include "lib/Exceptions.h"
```

### Example

Here is a simple example to demonstrate how to use the library:

#### Basic Usage

```c
#include <stdio.h>
#include "lib/Var.h"
#include "lib/Arrays.h"
#include "lib/Exceptions.h"

jmp_buf __ex_buf;
int __ex_code = 0;

int main() {
    var x = New(VAR_INT, 5);
    var y = New(VAR_INT, 10);
    
    var sum = New(VAR_INT, x.value.int_value + y.value.int_value);
    
    printf("Sum: %d\n", sum.value.int_value);
    
    return 0;
}
```

#### Arrays and Var

```c
#include <stdio.h>
#include "lib/Var.h"
#include "lib/Arrays.h"
#include "lib/Exceptions.h"

int main() {
    var array = NewArray(VAR_INT, 3);
    array.value.array_value[0] = New(VAR_INT, 1);
    array.value.array_value[1] = New(VAR_INT, 2);
    array.value.array_value[2] = New(VAR_INT, 3);
    
    for (int i = 0; i < 3; i++) {
        printf("Array[%d]: %d\n", i, array.value.array_value[i].value.int_value);
    }
    
    return 0;
}
```

#### Try-Catch

```c
#include <stdio.h>
#include "lib/Var.h"
#include "lib/Arrays.h"
#include "lib/Exceptions.h"

jmp_buf __ex_buf;
int __ex_code = 0;

int main() {
    if (__ex_code = setjmp(__ex_buf)) {
        printf("Exception caught: %d\n", __ex_code);
    } else {
        var x = New(VAR_INT, 5);
        var y = New(VAR_INT, 0);
        
        if (y.value.int_value == 0) {
            Throw(1); // Throwing an exception
        }
        
        var result = New(VAR_INT, x.value.int_value / y.value.int_value);
        printf("Result: %d\n", result.value.int_value);
    }
    
    return 0;
}
```

### Documentation

For detailed documentation, please refer to the [Wiki](https://github.com/yourusername/cello-lookalike/wiki).

### Contributing

We welcome contributions! Please read our [contributing guidelines](https://github.com/yourusername/cello-lookalike/blob/main/CONTRIBUTING.md) before submitting a pull request.

### License

This project is licensed under the MIT License. See the [LICENSE](https://github.com/yourusername/cello-lookalike/blob/main/LICENSE) file for details.