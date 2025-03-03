#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <setjmp.h>

extern jmp_buf __ex_buf;  // Déclaration
extern int __ex_code;     // Déclaration

#define try if ((__ex_code = setjmp(__ex_buf)) == 0)
#define catch else
#define throw(code) longjmp(__ex_buf, code)

#endif