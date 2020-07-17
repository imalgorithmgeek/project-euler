#include <bits/stdc++.h>
#include <chrono>

/* function prototype */
size_t largest_number_of(size_t number_of_digit);
size_t smallest_number_of(size_t number_of_digit);
size_t reverse_number(size_t number);
bool is_palindrome(size_t product);

int main(int argc, char* argv[]) {
    const size_t number_of_digit{3};

    size_t largest_number{largest_number_of(number_of_digit)};
    size_t smallest_number{smallest_number_of(number_of_digit)};

    /* calculate the time_required */
    auto start = std::chrono::high_resolution_clock::now();

    /* maximum will indicate the largest palindrome obtained so far */
    size_t maximum{0};

    /* loop from largest number to smallest number */
    for (size_t i{largest_number};i >= smallest_number;i--) {
        /* loop from largest number to smallest number */
        for (size_t j{largest_number};j >= i;j--) {
            size_t product{i*j};

            if (product <= maximum) {
                /* since value of product is always going to be
                 * smaller than whatever it currently is! */
                break;
            }
            /* if number is a palindrome and greater than the previously
             * obtained palindrome then update the maximum */
            if (is_palindrome(product)) {
                maximum = product;
            }
        }
    }
    auto stop = std::chrono::high_resolution_clock::now();

    /* print the time_required */
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Time taken: " << duration.count() << " microseconds" << std::endl;

    /* print the largest palindrome product */
    std::cout << maximum << std::endl;

    return 0;
}

/* a function to check whether a number is palindrome */
bool is_palindrome(size_t product) {
    return product == reverse_number(product);
}
/* a function to calculate the largest
 * number having number_of_digit */
size_t largest_number_of(size_t number_of_digit) {
    const size_t largest_digit{9};
    size_t number{0};
    for (size_t i{1};i <= number_of_digit;i++) {
        number = number * 10 + largest_digit;
    }
    return number;
}

/* a function to calculate the smallest
 * number having number_of_digit */
size_t smallest_number_of(size_t number_of_digit) {
    const size_t smallest_digit{0};
    size_t number{1};
    for (size_t i{1};i < number_of_digit;i++) {
        number = number * 10 + smallest_digit;
    }
    return number;
}

/* a function to obtain the reverse of a number */
size_t reverse_number(size_t number) {
    size_t reverse{0};
    while (number != 0) {
        reverse = reverse * 10 + (number%10);
        number /= 10;
    }
    return reverse;
}