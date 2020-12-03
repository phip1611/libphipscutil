#ifndef _VEC_H
#define _VEC_H

#include <stdlib.h>
#include <assert.h>
#include <stdint.h>

/// Each vector can store by default 1024 elements.
/// After each 1024 elements, 1024 more are added.
static const unsigned VEC_GOODSIZE_ELEMENTS = 1024;

// Dynamically growing-only vector. Elements can't be removed.
// All "vec_" functions are public interface. All "_vec_" functions
// are private. Vector can store items of 1, 2, 4, or 8 byte. If
// you want to store big items use pointers to the structures.
typedef struct vec {
    // The size in bytes for each stored item.
    // Stored items can be ints or pointers to structures.
    uint8_t item_size;
    // Size is the total number of elements in the vector.
    // size*itemsize is the consumed total memory.
    // Supported values for this vector are 1, 2, 4, and 8 bytes.
    uint64_t size;
    // The capacity in number items. This gets automatically increased when the vector grows.
    uint64_t capacity;
    // Pointer to raw data storage. Pointer may change over time.
    u_int8_t * data;
    // If the vector was heap or stack allocated.
    uint8_t is_heap_allocated;
    // The number of elements the capacity gets increased each time it is reached.
    // Choose a high value (like 100.000) if you have millions of values for better
    // performance.
    uint16_t elements_increase;
} vec_t;

// Creates a new vector on the heap that stores elements of the given type.
// Returns a pointer to the vector.
#define vec_new(type) \
    _vec_new(sizeof(type))

// Shorthand to create a new vector on the heap that stores elements of the given type.
#define vec_new_heap(varname, type) \
    struct vec * varname = vec_new(type);

// Shorthand to create a new vector on the stack that stores elements of the given type.
#define vec_new_stack(varname, type) \
    struct vec varname; \
    vec_stack_init(varname, type);

// Initializes a vector that was allocated on the stack.
#define vec_stack_init(varname, type) \
    varname.is_heap_allocated = 0; \
    _vec_init(&varname, sizeof(type))


// Allocates a new vector on the heap. Automatically calls _vec_init().
struct vec * _vec_new(size_t itemsize);

// Call this if you did stack allocation and want to init the vec.
// You don't have to do this if you called vec_new() already.
void _vec_init(struct vec * vec, size_t itemsize);

// Adds "value of property elements_increase" elements to the vectors data storage.
void _vec_grow(struct vec * vec);

// Adds a new element to the vector.
void vec_push(struct vec * vec, u_int64_t val);

// Prints information about vector. item_print_fn is either NULL
// or a function that make a single line string representation of the
// stored value without new line.
void vec_print(struct vec * vec, void (item_print_fn)(void*));

// Returns a reference to the value stored at the given index.
// Be aware that if you store pointers, you get a pointer to
// a pointer returned.
void * vec_get(struct vec * vec, uint32_t index);

// Frees the data of the vector but not the vector structure itself.
// If item_free_fn != NULL then each element will be applied to the given
// free function.
void vec_free(struct vec * vec, void (item_free_fn)(void*));

/**
 * Clears the vector (sets the stored items to zero). The vector keeps it's capacity.
 * @param vec Vector
 * @param overwrite_mem whether all used memory should be zeroed.
 */
void vec_clear(struct vec * vec, uint8_t overwrite_mem);

/**
 * Iterates through a vector. The var "entry_var_name" will be of type
 * ("type" *). The index_var_name will show the number of the current iteration.
 *
 * @param vec_var_name Name of the vector
 * @param type Type stored inside the vector (needed for type safety here)
 * @param entry_var_name Name of the var via that you can access the pointer to the current item
 * @param index_var_name  Name of the var via that you can access the iteration number
 */
#define vec_foreach(vec_var_name, type, entry_var_name, index_var_name) \
    type * entry_var_name;                         \
    uint64_t index_var_name;                           \
    for (index_var_name = 0, entry_var_name = (type*)vec_get(vec_var_name, index_var_name); \
        index_var_name < vec_var_name->size;             \
        index_var_name++, entry_var_name = (type*)vec_get(vec_var_name, index_var_name))





// Getter for current size (number of items)
uint64_t vec_get_size(struct vec * vec);

// Number in bytes per item.
uint8_t vec_get_item_size(struct vec * vec);

// Gets the current capacity.
uint64_t vec_get_capacity(struct vec * vec);

// Gets the elements increase property.
uint16_t vec_get_elements_increase(struct vec * vec);

// Sets the elements increase property.
void vec_set_elements_increase(struct vec * vec, uint16_t new_value);

#endif
