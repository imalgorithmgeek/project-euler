#include <bits/stdc++.h>
#include <chrono>

int main(int argc, char* argv[]) {
    const size_t perimeter{1000};

    /* calculate the time_required */
    auto start = std::chrono::high_resolution_clock::now();

    bool is_found{false};
    /* loop for possible value of i */
    for (size_t i{1}; i <= perimeter/3 && !is_found; i++) {
        /* loop for possible value of j */
        for (size_t j{i + 1}; j <= (perimeter - i - 1)/2 && !is_found; j++) {

            /* calculate the value of k */
            size_t k{perimeter - i - j};

            if (i*i + j*j == k*k) {
                /* if these are pythagorean triplet
                 * then output the product of triplets */
                std::cout << i * j * k << std::endl;
                is_found = true;
            }
        }
    }

    auto stop = std::chrono::high_resolution_clock::now();

    /* print the time_required */
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Time taken: " << duration.count() << " microseconds" << std::endl;

    return 0;
}