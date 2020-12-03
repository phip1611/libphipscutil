#include <stdio.h>
#include "cwambo.h"

void unsigned_int_printer(void * ptr);

int main() {
    // STACK ALLOCATED VECTOR
    vec_t vec_s_1;
    vec_stack_init(vec_s_1, unsigned int);
    // or in one line
    vec_new_stack(vec_s_2, unsigned int);

    // HEAP ALLOCATED VECTOR
    vec_t * vec_h_1 = vec_new(unsigned int);
    // or if you like:
    vec_new_heap(vec_h_2, unsigned int);

    // PUSHING ELEMENTS
    vec_push(&vec_s_1, 1337);
    vec_push(&vec_s_2, 42);
    vec_push(&vec_s_2, 99);
    vec_push(vec_h_1, 100);
    vec_push(vec_h_2, 500);

    vec_print(&vec_s_1, NULL);
    vec_print(&vec_s_2, unsigned_int_printer);
    vec_print(vec_h_1, unsigned_int_printer);
    vec_print(vec_h_2, NULL);
}

void unsigned_int_printer(void * ptr) {
    unsigned int val = *(unsigned int *)ptr;
    printf("%d", val);
}
