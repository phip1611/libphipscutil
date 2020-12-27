#include <cstdio>

// same as the C test but in C++

extern "C" {
    #include "phipscutil.h"
    #include "test_util.h"
}

int main() {
    struct vec * byte_vec = vec_new(uint8_t);
    struct vec * u16_vec = vec_new(uint16_t);
    struct vec * u32_vec = vec_new(uint32_t);
    struct vec * u64_vec = vec_new(uint64_t);

    vec_push(byte_vec, 0b00000001);
    vec_push(byte_vec, 0b10000000);
    vec_push(u16_vec, 0x000F);
    vec_push(u16_vec, 0xF000);
    vec_push(u32_vec, 0x0000000F);
    vec_push(u32_vec, 0xF0000000);
    vec_push(u64_vec, 0x000000000000000F);
    vec_push(u64_vec, 0xF000000000000000);

    uint8_t * u8ptr_0 = static_cast<uint8_t *>(vec_get(byte_vec, 0));
    uint8_t * u8ptr_1 = static_cast<uint8_t *>(vec_get(byte_vec, 1));
    if (*u8ptr_0 != 1) {
        fail_test("Should equal 0b00000001");
    }
    if (*u8ptr_1 != 0b10000000) {
        fail_test("Should equal 0b00000001");
    }

    uint16_t * u16ptr_0 = static_cast<uint16_t *>(vec_get(u16_vec, 0));
    uint16_t * u16ptr_1 = static_cast<uint16_t *>(vec_get(u16_vec, 1));
    if (*u16ptr_0 != 0x0F) {
        fail_test("Should equal 0x000F");
    }
    if (*u16ptr_1 != 0xF000) {
        fail_test("Should equal 0xF000");
    }

    uint32_t * u32ptr_0 = static_cast<uint32_t *>(vec_get(u32_vec, 0));
    uint32_t * u32ptr_1 = static_cast<uint32_t *>(vec_get(u32_vec, 1));
    if (*u32ptr_0 != 0x0F) {
        fail_test("Should equal 0x0000000F");
    }
    if (*u32ptr_1 != 0xF0000000) {
        fail_test("Should equal 0xF0000000");
    }

    uint64_t * u64ptr_0 = static_cast<uint64_t *>(vec_get(u64_vec, 0));
    uint64_t * u64ptr_1 = static_cast<uint64_t *>(vec_get(u64_vec, 1));
    if (*u64ptr_0 != 0x0F) {
        fail_test("Should equal 0x000000000000000F");
    }
    if (*u64ptr_1 != 0xF000000000000000) {
        fail_test("Should equal 0xF000000000000000");
    }

    printf("Process exited with 0: all tests are fine\n");
}


