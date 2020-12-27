# Phips C Utility library (libphipscutil)

This is a utility library for C/C++ projects written
in C. I created this mainly for fun, to practice, and
for educational reasons.

The basic idea is that you never use objects/structs
directly but always via the proper prefixed function
of the public API.

### Covered features
#### Vectors 
Here are two comparisions of _phipscutil_ Vec vs C++ Vec. **Lower is better**.
For everyday workloads the difference is negligible. If you need a high performance implementation
then my vec is better when adding massive data (200,000,000 * 64bit). C++ vec is faster
when adding massive small data (u8).
![bench phipscutil Vec vs C++ Vec (200,000 iterations)](res/phipscutil%20Vec%20und%20C++%20Vec%20(200,000%20Iterations).png "bench phipscutil Vec vs C++ Vec (200,000 iterations)")
![bench phipscutil Vec vs C++ Vec (200,000,000 iterations)](res/phipscutil%20Vec%20und%20C++%20Vec%20(200,000,000%20Iterations).png "bench phipscutil Vec vs C++ Vec (200,000,000 iterations)")

#### TODO Option(al)
#### TODO ReferenceCounter (RC)

### How to use
Download code via git or download it as ZIP.
Execute `sh build_n_install.sh`. On UNIX systems
header files will be installed into `/usr/local/include/phipscutil`
and the shared object (dynlib) into `/usr/local/lib`.
If you run `sh build[_n_install].sh` you will find examples
and benchmarks in `./build/`.


### Example
You can find more examples in `examples/` directory.
```c
#include <stdio.h>
#include <phipscutil/phipscutil.h>

// or in C++ project:
extern "C" {
    #include <phipscutil/phipscutil.h>
}

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

    printf("foreach begin: should print %lld items\n", vec_get_size(vec_h_1));

    // ENCAPSULATE EACH FOREACH IN A NEW BLOCK IF YOU WANT TO REUSE THE SAME
    // VARIABLE NAMES MULTIPLE TIMES ("entry", "index").
    {
        vec_foreach(vec_h_1, unsigned int, entry, index) {
            printf("%lld => %d\n", index, *entry);
        };
    }
    {
        vec_foreach(vec_h_2, unsigned int, entry, index) {
            printf("%lld => %d\n", index, *entry);
        };
    }


}

void unsigned_int_printer(void * ptr) {
    unsigned int val = *(unsigned int *)ptr;
    printf("%d", val);
}
```
##### Output:
```
Vec {
    size: 1
    capacity: 1024
    item_size: 4
    data: [<1 entries>]
}
Vec {
    size: 2
    capacity: 1024
    item_size: 4
    data: [
        42
        99
    ]
}
Vec {
    size: 1
    capacity: 1024
    item_size: 4
    data: [
        100
    ]
}
Vec {
    size: 1
    capacity: 1024
    item_size: 4
    data: [<1 entries>]
}
foreach begin: should print 1 items
0 => 100
0 => 500
```