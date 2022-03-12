#include <iostream>
#include <cassert>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    unsigned long long previous = 0;
    unsigned long long current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        unsigned long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous % 10;
        previous = current;
        current = (tmp_previous + current) % 10;
    }

    return current % 10;

}

void test_solution() {
    for (int n = 0; n < 100; ++n){
        assert(get_fibonacci_last_digit_fast(n) == get_fibonacci_last_digit_naive(n));
        std::cout << n << std::endl;
    }
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    int c_f = get_fibonacci_last_digit_fast(n);
    // std::cout << c << '\n';
    std::cout << c_f<< "\n";
    
    // test_solution();

    return 0;
    }
