#include <bits/stdc++.h>
#include <chrono>

/* function prototype */
size_t SieveOfEratosthenes(size_t upper_limit);

int main(int argc, char* argv[]) {
    const size_t upper_limit{2000000};

    /* calculate the time_required */
    auto start = std::chrono::high_resolution_clock::now();

    /* get the prime numbers upto upper_limit */
    size_t total_sum = SieveOfEratosthenes(upper_limit);

    auto stop = std::chrono::high_resolution_clock::now();

    /* print the time_required */
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Time taken: " << duration.count() << " microseconds" << std::endl;

    /* print the total_sum */
    std::cout << total_sum << std::endl;
    return 0;
}

size_t SieveOfEratosthenes(size_t upper_limit) {
    size_t limit{upper_limit + 1};
    bool* array = new bool[limit];

    /* initialize the array which will indicate
     * information about prime numbers */
    for (size_t i{0};i < limit;i++) {
        array[i] = true;
    }

    for (size_t i{2};i*i < limit;i++) {

        /* if array[i] is true then i is a prime */
        if (array[i]) {
            size_t j{i*i};
            /* numbers which are multiple of i && are
             * less than i*i are already been marked */

            while (j < limit) {
                /* update all multiples of i greater than j */
                array[j] = false;
                j += i;
            }
        }
    }

    size_t total{0};
    /* insert prime numbers in the vector */
    for (size_t i{2};i < limit;i++) {
        if (array[i]) {
            total += i;
        }
    }

    /* de-allocate the heap memory */
    delete [] array;

    return total;
}