#include <bits/stdc++.h>

/* function prototype */
size_t fibonacci_generator(size_t upper_limit);

int main(int argc, char* argv[]) {
    size_t upper_limit{4000000};

    /* calculate the sum of even fibonacci numbers */
    size_t even_fibonacci_sum = fibonacci_generator(upper_limit);

    /* print the result */
    std::cout << even_fibonacci_sum << std::endl;
    return 0;
}

size_t fibonacci_generator(size_t upper_limit) {
    size_t first_sequence{1}, second_sequence{1}, third_sequence{first_sequence + second_sequence};

    /* initialize the sum variable */
    size_t sum{0};

    /* only even fibonacci numbers will be generated */
    while (third_sequence < upper_limit) {
        sum += third_sequence;
        first_sequence = second_sequence + third_sequence;
        second_sequence = third_sequence + first_sequence;
        third_sequence = first_sequence + second_sequence;
    }
    return sum;
}