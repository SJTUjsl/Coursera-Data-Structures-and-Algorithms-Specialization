#include <iostream>
#include <vector>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

int fibonacci_sum_squares_fast(long long n){
    std::vector<int> periodical;   // Pisano 周期数列
	int previous = 0;
	int current = 1;
	periodical.push_back(0);
	periodical.push_back(1);

    int p_size = periodical.size();
	while (periodical.size()<60) {
		int tmp_previous = previous % 10;
		previous = current % 10;
		current = tmp_previous + current % 10;
		periodical.push_back(current % 10);
	}
    int idx = n % 60;
	return periodical[idx] * periodical[idx + 1] % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n);
}
