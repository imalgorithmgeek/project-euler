#include <bits/stdc++.h>
#include <chrono>

/* function prototype */
void SieveOfEratosthenes(std::vector<size_t>& prime_numbers,size_t upper_limit);

int main(int argc, char* argv[]) {
    const size_t upper_limit{20};

    /* calculate the time_required */
    auto start = std::chrono::high_resolution_clock::now();

    /* get the prime numbers upto upper_limit */
    std::vector<size_t> prime_numbers;
    SieveOfEratosthenes(prime_numbers, upper_limit);

    /* initialize the array containing elements
     * whose smallest multiple needs to calculate */
    auto* array = new size_t[upper_limit];
    for (size_t i{0};i < upper_limit;i++) {
        array[i] = (i + 1);
    }

    /* declare variable to store smallest_multiple */
    size_t smallest_multiple{1};

    /* declare boolean variable to indicate the requirement of next
     * iteration and availability of factor of a prime number */
    bool is_next_iteration, is_prime_factor_available;

    /* size of total primes which are less than upper_limit */
    size_t number_of_primes{prime_numbers.size()};

    /* loop for each prime number until elements of
     * the array have only one factor called 1 */
    for (size_t i{0};i < number_of_primes;i++) {
        do {
            /* start the iteration by assuming that element
             * aren't multiple of current prime number */
            is_prime_factor_available = false;

            /* loop for each element of the array */
            for (size_t j{0}; j < upper_limit; j++ ) {
                if (array[j] % prime_numbers.at(i) == 0) {
                    /* if array[j] has a factor of prime_number.at(i) */
                    is_prime_factor_available = true;
                    array[j] /= prime_numbers.at(i);
                }
            }

            if (is_prime_factor_available) {
                /* if an array element has a prime factor */
                smallest_multiple *= prime_numbers.at(i);
            }
        } while (is_prime_factor_available);

        /* assume that further processing isn't required */
        is_next_iteration = false;

        for (size_t j{0};j < upper_limit;j++) {

            if (array[j] != 1) {
                /* if their may be some elements having prime
                 * factors then further processing is required */
                is_next_iteration = true;
                break;
            }
        }

        /* if further processing isn't required */
        if (!is_next_iteration) {
            break;
        }
    }
    auto stop = std::chrono::high_resolution_clock::now();

    /* print the time_required */
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Time taken: " << duration.count() << " microseconds" << std::endl;

    /* print the smallest multiple */
    std::cout << smallest_multiple << std::endl;
    return 0;
}

void SieveOfEratosthenes(std::vector<size_t>& prime_numbers, size_t upper_limit) {
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

    /* insert prime numbers in the vector */
    for (size_t i{2};i < limit;i++) {
        if (array[i]) {
            prime_numbers.push_back(i);
        }
    }

    /* de-allocate the heap memory */
    delete [] array;
}