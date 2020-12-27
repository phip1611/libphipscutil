#include "test_util.h"
#include "phipscutil.h"

// like the cpp test but without binary string literals

#define Ob00000001 1
#define Ob10000000 (1 << (8-1))
#define Ob00001111 15
#define Ob11110000_16 (Ob00001111 << (16 - 4))
#define Ob11110000_32 (((uint32_t) Ob00001111) << (32 - 4))
#define Ob11110000_64 (((uint64_t) Ob00001111) << (64 - 4))
#define Ox0F Ob00001111
#define OxF000 Ob11110000_16
#define OxF0000000 Ob11110000_32
#define OxF000000000000000 Ob11110000_64

int main() {
    struct vec * byte_vec = vec_new(uint8_t);
    struct vec * u16_vec = vec_new(uint16_t);
    struct vec * u32_vec = vec_new(uint32_t);
    struct vec * u64_vec = vec_new(uint64_t);

    vec_push(byte_vec, Ob00000001);
    vec_push(byte_vec, Ob10000000);
    vec_push(u16_vec, Ob00001111); // 0b1111 or 0xf
    // 0b11110000_00000000
    vec_push(u16_vec, Ob11110000_16);
    vec_push(u32_vec, Ob00001111);
    vec_push(u32_vec, Ob11110000_32);
    vec_push(u64_vec, Ob00001111);
    vec_push(u64_vec, Ob11110000_64);

    uint8_t * u8ptr_0 = vec_get(byte_vec, 0);
    uint8_t * u8ptr_1 = vec_get(byte_vec, 1);
    if (*u8ptr_0 != 1) {
        fail_test("Should equal 0b00000001");
    }
    if (*u8ptr_1 != Ob10000000) {
        fail_test("Should equal 0b00000001");
    }

    uint16_t * u16ptr_0 = vec_get(u16_vec, 0);
    uint16_t * u16ptr_1 = vec_get(u16_vec, 1);
    if (*u16ptr_0 != Ox0F) {
        fail_test("Should equal 0x000F");
    }
    if (*u16ptr_1 != OxF000) {
        fail_test("Should equal 0xF000");
    }

    uint32_t * u32ptr_0 = vec_get(u32_vec, 0);
    uint32_t * u32ptr_1 = vec_get(u32_vec, 1);
    if (*u32ptr_0 != Ox0F) {
        fail_test("Should equal 0x0000000F");
    }
    if (*u32ptr_1 != OxF0000000) {
        fail_test("Should equal 0xF0000000");
    }

    uint64_t * u64ptr_0 = vec_get(u64_vec, 0);
    uint64_t * u64ptr_1 = vec_get(u64_vec, 1);
    if (*u64ptr_0 != Ox0F) {
        fail_test("Should equal 0x000000000000000F");
    }
    if (*u64ptr_1 != OxF000000000000000) {
        fail_test("Should equal 0xF000000000000000");
    }

    printf("Process exited with 0: all tests are fine\n");
}


