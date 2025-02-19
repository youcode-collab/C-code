#include <stdio.h>
#include "Types.h"
#include <stdarg.h>
#include <string.h>
typedef struct Var{
    var_type type;
    union{
        int int_value;
        float float_value;
        char* string_value;
        //bool bool_value;
    }value;
    struct Var (*New)(var_type type, void* value);
}var;

//Var Methods
var New(var_type type, ...) {
    var v;
    v.type = type;

    va_list args;
    va_start(args, type);

    switch (type) {
        case VAR_INT:
            v.value.int_value = va_arg(args, int);
            break;
        case VAR_FLOAT:
            v.value.float_value = (float)va_arg(args, double);
            break;
        case VAR_STRING:{
            const char* temp = va_arg(args, const char*);
            v.value.string_value = strdup(temp);
            break;
        }
        case VAR_NULL:
            break;
    }

    va_end(args);
    return v;
}