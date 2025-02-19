#include "Var.h"
#include <stdlib.h>

typedef struct Array{
    var* data;
    size_t length;
    struct Array* (*array)();
    int (*push)(struct Array* arr, var value);
}Array;

Array* array();
int push(Array* arr, var value);

Array* array() {
    Array* arr = (Array*)malloc(sizeof(Array));
    arr->data = NULL;
    arr->length = 0;
    arr->push = push;
    // arr->array = array;
    return arr;
}

int push(Array* arr, var value){
    Array* a = arr;
    if(a->length == 0){
        a->data = &value;
    }else{
        while(a->data != NULL){
            a = a->data;
        }
        a->data = &value;
    }
    arr->length++;
    return 1;
}

// var pop(Var* arr){
//     if(arr->length == 0){
//         return NULL;
//     }
//     arr->length--;
//     arr->data = realloc(arr->data, arr->length * sizeof(var));
//     return arr->data[arr->length];
// }

// void unshift(Var* arr){
//     arr->length++;
//     arr->data = realloc(arr->data, arr->length * sizeof(var));
//     for(int i = arr->length - 1; i > 0; i--){
//         arr->data[i] = arr->data[i - 1];
//     }
// }

// var shift(Var* arr){
//     if(arr->length == 0){
//         return NULL;
//     }
//     arr->length--;
//     arr->data = realloc(arr->data, arr->length * sizeof(var));
//     var temp = arr->data[0];
//     for(int i = 0; i < arr->length; i++){
//         arr->data[i] = arr->data[i + 1];
//     }
//     return temp;
// }