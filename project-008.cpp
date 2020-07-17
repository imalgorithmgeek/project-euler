#include <bits/stdc++.h>
#include <chrono>

int main(int argc, char* argv[]) {
    const size_t upper_limit{1000};
    const size_t adjacent_digits{13};

    std::string number;
    /* read the string */
    std::cin >> number;

    /* calculate the time_required */
    auto start = std::chrono::high_resolution_clock::now();

    /* declare variable for temp_product
     * and global_maximum product */
    size_t temp_product;
    size_t maximum_product{0};

    /* loop through each possible iteration */
    for (size_t i{0};i <= upper_limit-adjacent_digits;i++) {
        /* initialize the temp_product */
        temp_product = 1;

        /* calculate the product of 13 adjacent_digits */
        for (size_t j{0};j < adjacent_digits;j++) {
            temp_product *= static_cast<size_t>(number.at(i + j) - '0');
        }

        /* if temp_product obtained is greater than
         * maximum_product then update maximum_product */
        if (temp_product > maximum_product) {
            maximum_product = temp_product;
        }
    }

    auto stop = std::chrono::high_resolution_clock::now();

    /* print the time_required */
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Time taken: " << duration.count() << " microseconds" << std::endl;

    /* print the maximum_product */
    std::cout << maximum_product << std::endl;

    return 0;
}