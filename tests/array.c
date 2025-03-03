#include "../lib/Arrays.h"
#include "../lib/Exceptions.h"

jmp_buf __ex_buf;
int __ex_code = 0;

var sum(var a, var b){
    try{
        if (a.type == VAR_INT && b.type == VAR_INT) {
            return New(VAR_INT, a.value.int_value + b.value.int_value);
        } else if (a.type == VAR_FLOAT && b.type == VAR_FLOAT) {
            return New(VAR_FLOAT, a.value.float_value + b.value.float_value);
        } else if (a.type == VAR_INT && b.type == VAR_FLOAT) {
            return New(VAR_FLOAT, a.value.int_value + b.value.float_value);
        } else if (a.type == VAR_FLOAT && b.type == VAR_INT) {
            return New(VAR_FLOAT, a.value.float_value + b.value.int_value);
        } else {
            throw(1);
        }
    }catch{
        printf("Error in sum [%d]\n", __ex_code);
        return New(VAR_INT, 0);
    }
}

int main(){
    Array* a = array();
    a->push(a, New(VAR_INT, 20));
    a->push(a, New(VAR_INT, 10));
    a->push(a, New(VAR_INT, 30));
    a->push(a, New(VAR_STRING, "Hello"));
    a->push(a, New(VAR_INT, -1));
    printf("length:%zu\n", a->length);
    a->foreach(a, print);
    //a->pop(a);
    printf("length:%zu\n", a->length);
    a->foreach(a, print);
    printf("reduce value: %d\n",a->reduce(a, sum, New(VAR_INT, 0)).value.int_value);
    a->sort(a, compare_var);
    a->foreach(a, print);
    int value = -1;
    printf("index of 20: %d\n", a->findIndex(a, &value));

    return 0;
}