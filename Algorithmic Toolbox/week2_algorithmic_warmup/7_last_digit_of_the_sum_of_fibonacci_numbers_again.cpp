#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

long long get_fibonacci_partial_sum_fast(long long from, long long to) {
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

	int idx_from = (from + 1) % 60;
    int idx_to = (to + 2) % 60;
    if(from == to)
        return periodical[from % 60];
    else
	    return ((periodical[idx_to] + 9) % 10 - (periodical[idx_from] + 9) % 10 + 10) % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    //std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';

    return 0;
}
