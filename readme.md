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
    
    printf("Sum: %d\n", x.value.int_value); //5
    
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
    Array* a = array();
    a->push(a, New(VAR_INT, 20));
    a->push(a, New(VAR_INT, 10));
    a->push(a, New(VAR_INT, 30));
    a->push(a, New(VAR_STRING, "Hello"));
    printf("length:%zu\n", a->length); // 4
    a->foreach(a, print); // 20 10 30 Hello
    a->sort(a, compare_var); // 10 20 30 Hello
    
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
    int test = 0;
    try{
        if(test == 0)
            throw(1)
    }catch{
        printf("Error code [%d]\n", __ex_code);
        printf("test variable is 0");
    }
    
    return 0;
}
```

### Contributing

We welcome contributions! Please fork and add your magic.
