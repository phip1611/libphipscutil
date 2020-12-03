#include <string.h>
#include <stdio.h>
#include "vec.h"

__always_inline struct vec *_vec_new(size_t itemsize) {
    struct vec *vec = malloc(sizeof(struct vec));
    vec->is_heap_allocated = 1;
    _vec_init(vec, itemsize);
    return vec;
}

__always_inline void _vec_init(struct vec *vec, size_t itemsize) {
    vec->item_size = itemsize;
    vec->size = 0;
    vec->data = NULL;
    vec->elements_increase = VEC_GOODSIZE_ELEMENTS;
    _vec_grow(vec);
}

// Adds VEC_GOODSIZE_ELEMENTS to the data of the vector.
__always_inline void _vec_grow(struct vec *vec) {
    // fprintf(stderr, "vec: _vec_grow invoked\n");
    // during initialization of vector
    if (vec->data == NULL) {
        vec->capacity = vec->elements_increase;
        vec->data = malloc(vec->capacity * vec->item_size);
    } else {
        // measured in number of items
        vec->capacity  = vec->capacity + vec->elements_increase;
        size_t new_capacity_bytes = vec->capacity * vec->item_size;
        // returns either the same pointer if the memory region was increased
        // or returns a pointer to the new location.
        // it automatically moves old data to the new region and frees
        // the old pointer.
        vec->data = (uint8_t *) realloc(vec->data, new_capacity_bytes);
    }
}

__always_inline  void vec_push(struct vec *vec, u_int64_t val) {
    if (vec->size == vec->capacity) {
        _vec_grow(vec);
    }

    // vec->size always points on the next free index
    // unsigned next_index = _vec_calc_internal_index(vec, vec->size + 1);
    switch (vec->item_size) {
        case 1: // 1 byte
        {
            vec->data[vec->size] = val;
            break;
        }
        case 2: // 2 byte
        {
            uint16_t * u16_data_ptr = (uint16_t *) vec->data;
            u16_data_ptr[vec->size] = val;
            break;
        }
        case 4: // 4 byte, 32bit
        {
            uint32_t *u32_data_ptr = (uint32_t *) vec->data;
            u32_data_ptr[vec->size] = val;
            break;
        }
            break;
        case 8: // 8 byte, 64bit
        {
            uint64_t *u64_data_ptr = (uint64_t *) vec->data;
            u64_data_ptr[vec->size] = val;
            break;
        }
        default:
            assert("Only values with a size of 1, 2, 4, or 8 bytes can be directly pushed. Use pointers for lager structures instead!");
    }
    vec->size++;
}

__always_inline void vec_print(struct vec *vec, void (item_print_fn)(void *)) {
    printf("Vec {\n");
    printf("    size: %ld\n", vec->size);
    printf("    capacity: %ld\n", vec->capacity);
    printf("    item_size: %d\n", vec->item_size);
    if (item_print_fn == NULL) {
        printf("    data: [<%ld entries>]\n", vec->size);
    } else {
        printf("    data: [\n");
        for (unsigned long i = 0; i < vec->size; i++) {
            printf("        ");
            void *elem = vec_get(vec, i);
            item_print_fn(elem);
            printf("\n");
        }
        printf("    ]\n");
    }
    printf("}\n");
}

__always_inline void *vec_get(struct vec *vec, uint32_t index) {
    assert(index <= vec->size && "The index is out of bounds");
    switch (vec->item_size) {
        case 1: // 1 byte
            return &vec->data[index];
        case 2: // 2 byte
        {
            uint16_t *u16_data_ptr = (uint16_t *) vec->data;
            return &u16_data_ptr[index];
        }
        case 4: // 4 byte, 32bit
        {
            uint32_t *u32_data_ptr = (uint32_t *) vec->data;
            return &u32_data_ptr[index];
        }
        case 8: // 8 byte, 64bit
        {
            uint64_t *u64_data_ptr = (uint64_t *) vec->data;
            return &u64_data_ptr[index];
        }
        default:
            assert("Only values with a size of 1, 2, 4, or 8 bytes can be directly pushed. Use pointers for lager structures instead!");
    }
    return NULL;
}

__always_inline void vec_free(struct vec *vec, void (item_free_fn)(void *)) {
    if (item_free_fn != NULL) {
        for (unsigned long i = 0; i < vec->size; i++) {
            item_free_fn(
                    vec_get(vec, i)
            );
        }
    }
    memset(vec->data, 0, vec->size); // clear used data
    free(vec->data); // free data allocation
    if (vec->is_heap_allocated) {
        free(vec);
    }
}

__always_inline void vec_clear(struct vec * vec, uint8_t overwrite_mem) {
    if (overwrite_mem) {
        memset(vec->data, 0, vec->size);
    }
    vec->size = 0;
}

__always_inline uint64_t vec_get_size(struct vec *vec) {
    return vec->size;
}

__always_inline uint8_t vec_get_item_size(struct vec *vec) {
    return vec->item_size;
}

__always_inline uint64_t vec_get_capacity(struct vec *vec) {
    return vec->capacity;
}

__always_inline uint16_t vec_get_elements_increase(struct vec * vec) {
    return vec->elements_increase;
}

__always_inline void vec_set_elements_increase(struct vec * vec, uint16_t new_value) {
    vec->elements_increase = new_value;
}

