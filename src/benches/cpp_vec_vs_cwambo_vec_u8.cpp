#include <vector>
#include <chrono>  // for high_resolution_clock
#include <iostream>

// MAKE SURE TO RUN THIS BINARY IN RELEASE/PROD MODE! ONLY IN THIS CASE
// YOU GET COMPARABLE RESULTS.

extern "C" {
    #include "phipscutil.h"
}

uint64_t ITERATIONS = 500000000;

int main() {
    struct vec cwambo_vec {};
    vec_stack_init(cwambo_vec, uint8_t);
    // with this option we are faster than the std vector
    // vec_set_elements_increase(&cwambo_vec, 0x4000); // 16KB
    std::vector<uint8_t> cppvec;

    // cwambo vector
    {
        // Record start time
        auto start = std::chrono::high_resolution_clock::now();

        for (uint64_t i = 0; i < ITERATIONS; i++) {
            vec_push(&cwambo_vec, i);
        }

        // Record end time
        auto finish = std::chrono::high_resolution_clock::now();
        assert(vec_get_size(&cwambo_vec) == ITERATIONS);
        auto duration = std::chrono::duration_cast<std::chrono::microseconds> (finish - start);
        double us = duration.count();
        double s = us / 1000000;

        std::cout << "Inserting " << ITERATIONS << " (uint8_t) Elements into cwambo vector took : " << s << "s" << std::endl;
    }

    // std c++ vector
    {
        // Record start time
        auto start = std::chrono::high_resolution_clock::now();

        for (uint64_t i = 0; i < ITERATIONS; i++) {
            cppvec.push_back(i);
        }

        // Record end time
        auto finish = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds> (finish - start);
        double us = duration.count();
        double s = us / 1000000;

        std::cout << "Inserting " << ITERATIONS << " (uint8_t) Elements into std cpp vector took: " << s << "s" << std::endl;
    }

}


