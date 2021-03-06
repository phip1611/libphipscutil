#include <vector>
#include <chrono>  // for high_resolution_clock
#include <iostream>

// MAKE SURE TO RUN THIS BINARY IN RELEASE/PROD MODE! ONLY IN THIS CASE
// YOU GET COMPARABLE RESULTS.

extern "C" {
    #include "phipscutil.h"
}

uint64_t ITERATIONS = 200000000;

int main() {
    struct vec libphipscutil_vec {};
    vec_stack_init(libphipscutil_vec, uint64_t);
    // with this option we are faster than the std vector
    // vec_set_elements_increase(&libphipscutil_vec, 0x4000); // 16KB
    std::vector<uint64_t> cppvec;

    // libphipscutil vector
    {
        // Record start time
        auto start = std::chrono::high_resolution_clock::now();

        for (uint64_t i = 0; i < ITERATIONS; i++) {
            vec_push(&libphipscutil_vec, i);
        }

        // Record end time
        auto finish = std::chrono::high_resolution_clock::now();
        assert(vec_get_size(&libphipscutil_vec) == ITERATIONS);
        auto duration = std::chrono::duration_cast<std::chrono::microseconds> (finish - start);
        double us = duration.count();
        double s = us / 1000000;

        std::cout << "Inserting " << ITERATIONS << " (uint64_t) Elements into libphipscutil vector took : " << s << "s" << std::endl;
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

        std::cout << "Inserting " << ITERATIONS << " (uint64_t) Elements into std cpp vector took: " << s << "s" << std::endl;
    }

}


