#include <bits/stdc++.h>
#include <chrono>

int main(int argc, char* argv[]) {
    const size_t limit{100};

    /* calculate the time_required */
    auto start = std::chrono::high_resolution_clock::now();

    /* calculate the difference between the sum of the squares
     * of first 100 natural numbers and the square of the sum */
    size_t total_sum{(limit*(limit-1)*(limit+1)*(3*limit+2))/12};

    auto stop = std::chrono::high_resolution_clock::now();

    /* print the time_required */
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Time taken: " << duration.count() << " microseconds" << std::endl;

    /* print the difference between the sum of the squares the square of the sum */
    std::cout << total_sum << std::endl;

    return 0;
}