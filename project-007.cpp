#include <bits/stdc++.h>
#include <chrono>

/* function prototype */
size_t next_prime(std::vector<size_t>& prime_number, size_t start_index);

int main(int argc, char* argv[]) {
    const size_t upper_limit{10001};

    /* calculate the time_required */
    auto start = std::chrono::high_resolution_clock::now();

    /* create a container to store prime_numbers */
    std::vector<size_t > prime_number{2};

    size_t prime_count{1};
    size_t start_index{2};

    do {
        start_index = next_prime(prime_number, start_index);
        prime_count++;
    } while (prime_count < upper_limit);

    auto stop = std::chrono::high_resolution_clock::now();

    /* print the time_required */
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Time taken: " << duration.count() << " microseconds" << std::endl;

    /* print the prime_number */
    std::cout << prime_number.back() << std::endl;

    return 0;
}

/* a function to calculate the next prime number */
size_t next_prime(std::vector<size_t>& prime_number, size_t start_index) {
    /* create the start position for finding the next prime */
    size_t j{start_index};

    /* loop until prime_number is obtained */
    while (true) {
        bool is_prime{true};

        /* loop through each the prime number
         * available in the container */
        for (auto prime: prime_number) {
            if (j % prime == 0) {
                is_prime = false;
                break;
            }
        }

        if (is_prime) {
            /* if prime_number has been found */
            prime_number.push_back(j);
            break;
        } else {
            /* if prime_number hasn't been found */
            j += 1;
        }
    }
    return j;
}