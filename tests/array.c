#include "../lib/Arrays.h"

int main(){
    Array* a = array();
    a->push(a, New(VAR_INT, 10));
    return 0;
}