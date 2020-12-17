#include "phipscutil.h"

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

    uint8_t * u8ptr_0 = vec_get(byte_vec, 0);
    uint8_t * u8ptr_1 = vec_get(byte_vec, 1);
    assert(*u8ptr_0 == 0b00000001 && "Should equal 0b00000001");
    assert(*u8ptr_1 == 0b10000000 && "Should equal 0b10000000");

    uint16_t * u16ptr_0 = vec_get(u16_vec, 0);
    uint16_t * u16ptr_1 = vec_get(u16_vec, 1);
    assert(*u16ptr_0 == 0x000F && "Should equal 0x000f");
    assert(*u16ptr_1 == 0xF000 && "Should equal 0xF000");

    uint32_t * u32ptr_0 = vec_get(u32_vec, 0);
    uint32_t * u32ptr_1 = vec_get(u32_vec, 1);
    assert(*u32ptr_0 == 0x0000000F && "Should equal 0x0000000F");
    assert(*u32ptr_1 == 0xF0000000 && "Should equal 0xF0000000");

    uint64_t * u64ptr_0 = vec_get(u64_vec, 0);
    uint64_t * u64ptr_1 = vec_get(u64_vec, 1);
    assert(*u64ptr_0 == 0x000000000000000F && "Should equal 0x000000000000000F");
    assert(*u64ptr_1 == 0xF000000000000000 && "Should equal 0xF000000000000000");
}


