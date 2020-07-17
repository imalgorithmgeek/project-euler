#include <bits/stdc++.h>
#include <chrono>

/* function prototype */
size_t prime_factor(size_t number);

int main(int argc, char* argv[]) {
    const size_t number{600851475143};
    /*Scope Creation to find the running time */
    {
        /* calculate the time_required */
        auto start = std::chrono::high_resolution_clock::now();
        size_t largest_prime_factor = prime_factor(number);
        auto stop = std::chrono::high_resolution_clock::now();

        /* print the time_required */
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        std::cout << "Time taken: " << duration.count() << " microseconds" << std::endl;

        /* print the largest_prime_factor */
        std::cout << largest_prime_factor << std::endl;
    }
    return 0;
}

/* a function to calculate the largest prime factor of a number */
size_t prime_factor(size_t number) {
    size_t previous, current;

    if (number % 2 == 0) {
        /* if 2 is a prime factor of the number */
        previous = 2;
        number /= 2;

        /* remove all factor of 2 */
        while (number % 2 == 0) {
            number /= 2;
        }
    } else {
        /* if 2 isn't a prime factor of the number */
        previous = 1;
    }
    current = 3;
    size_t largest_factor{static_cast<size_t>(std::sqrt(number))};

    /* loop until number is greater than 1 and current_factor is
     * less than or equal to largest_factor */
    while (number > 1 && current <= largest_factor) {
        if (number % current == 0) {
            /* if current_factor is a factor of the number */
            number /= current;
            previous = current;

            /* remove all factor of number equals value current_factor */
            while (number % current == 0) {
                number /= current;
            }
            /* update the largest_factor possible */
            largest_factor = static_cast<size_t>(std::sqrt(number));
        }

        current += 2;
    }

    /* return the largest_factor */
    return (number == 1)? previous: number;
}