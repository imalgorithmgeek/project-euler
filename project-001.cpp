#include <bits/stdc++.h>

/* function prototype */
size_t sum_divisible_by(size_t number, size_t upper_limit);

int main(int argc, char* argv[]) {
    size_t upper_limit{1000};
    size_t total_sum;
    total_sum = sum_divisible_by(3, upper_limit) +
                sum_divisible_by(5, upper_limit) -
                sum_divisible_by(15, upper_limit);
    std::cout << total_sum << std::endl;
    return 0;
}

/* function to calculate the sum of multiples
 * of a given number upto an upper_limit */
size_t sum_divisible_by(size_t number, size_t upper_limit) {
    size_t iteration_count{(upper_limit - 1)/number};
    return (iteration_count*(iteration_count + 1)/2) * number;
}