#include <stdio.h>
#include "../lib/Var.h"

int main(void)
{
    var v;
    v.type = VAR_INT;
    v.value.int_value = 10;
    printf("%d\n", v.value.int_value);
    var x = New(VAR_INT, 11);
    printf("%d\n", x.value.int_value);
    var y = New(VAR_FLOAT, 12.5);
    printf("%f\n", y.value.float_value);
    var z = New(VAR_STRING, "Hello, World!");
    printf("%s\n", z.value.string_value);
}