#include <stdio.h>
#include "Types.h"
typedef struct Var{
    var_type type;
    union{
        int int_value;
        float float_value;
        char* string_value;
        bool bool_value;
    }value;
}var;

typedef struct Array{
    var* data;
    size_t size;
    size_t (*size)(Array*);
    void (*push)(Array*, var);
    var (*pop)(Array*);
    void (*unshift)(Array*, var);
    var (*shift)(Array*);
}Array;