#include "Var.h"
#include <stdlib.h>
#include <string.h>

typedef struct Array{
    var* data;
    size_t length;
    struct Array* (*array)();
    int (*push)(struct Array* arr, var value);
    var (*pop)(struct Array* arr);
    void (*foreach)(struct Array* arr, void (*func)(var));
    var (*reduce)(struct Array* arr, var (*func)(var, var), var initial);
    void (*sort)(struct Array* arr, int (*compare)(var, var));
    int (*findIndex)(struct Array* arr, void* value);
} Array;

Array* array();
int push(Array* arr, var value);
var pop(Array* arr);
void foreach(Array* arr, void (*func)(var));
var reduce(Array* arr, var (*func)(var, var), var initial);
void sort(Array* arr, int (*compare)(var, var));
int findIndex(Array* arr, void* value);

Array* array() {
    Array* arr = (Array*)malloc(sizeof(Array));
    arr->data = NULL;
    arr->length = 0;
    arr->push = push;
    arr->pop = pop;
    arr->foreach = foreach;
    arr->reduce = reduce;
    arr->sort = sort;
    arr->findIndex = findIndex;
    return arr;
}

int push(Array* arr, var value){
    if(arr == NULL || value.type == VAR_NULL){
        return 0;
    }
    if(arr->length == 0){
        arr->data = (var*)malloc(sizeof(var));
    } else {
        arr->data = (var*)realloc(arr->data, (arr->length + 1) * sizeof(var));
    }
    arr->data[arr->length] = value;
    arr->length++;
    return 1;
}

var pop(Array* arr){
    if(arr->length == 0){
        var null_var;
        null_var.type = VAR_NULL;
        return null_var;
    }
    var value = arr->data[arr->length - 1];
    arr->length--;
    arr->data = (var*)realloc(arr->data, arr->length * sizeof(var));
    return value;
}

void print(var v) {
    switch (v.type) {
        case VAR_INT:
            printf("%d ", v.value.int_value);
            break;
        case VAR_FLOAT:
            printf("%f ", v.value.float_value);
            break;
        case VAR_STRING:
            printf("%s ", v.value.string_value);
            break;
        case VAR_NULL:
            printf("NULL");
            break;
    }
}

void foreach(Array* arr, void (*func)(var)) {
    for(size_t i = 0; i < arr->length; i++) {
        func(arr->data[i]);
    }
}

var reduce(Array* arr, var (*func)(var, var), var initial) {
    var result = initial;
    for(size_t i = 0; i < arr->length; i++) {
        result = func(result, arr->data[i]);
    }
    return result;
}

int compare_var(var a, var b) {
    if (a.type != b.type) {
        return a.type - b.type;
    }
    switch (a.type) {
        case VAR_INT:
            return a.value.int_value - b.value.int_value;
        case VAR_FLOAT:
            return (a.value.float_value > b.value.float_value) - (a.value.float_value < b.value.float_value);
        case VAR_STRING:
            return strcmp(a.value.string_value, b.value.string_value);
        default:
            return 0;
    }
}

void sort(Array* arr, int (*compare)(var, var)) {
    for (size_t i = 0; i < arr->length - 1; i++) {
        for (size_t j = 0; j < arr->length - i - 1; j++) {
            if (compare(arr->data[j], arr->data[j + 1]) > 0) {
                var temp = arr->data[j];
                arr->data[j] = arr->data[j + 1];
                arr->data[j + 1] = temp;
            }
        }
    }
}

int findIndex(Array* arr, void* value) {
    for (size_t i = 0; i < arr->length; i++) {
        switch (arr->data[i].type) {
            case VAR_INT:
                if (arr->data[i].value.int_value == *(int*)value) {
                    return i;
                }
                break;
            case VAR_FLOAT:
                if (arr->data[i].value.float_value == *(float*)value) {
                    return i;
                }
                break;
            case VAR_STRING:
                if (strcmp(arr->data[i].value.string_value, (char*)value) == 0) {
                    return i;
                }
                break;
            default:
                break;
        }
    }
    return -1; // Retourne -1 si l'élément n'est pas trouvé
}