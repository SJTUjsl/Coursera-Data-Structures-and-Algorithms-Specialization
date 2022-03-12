#include <iostream>
#include <vector>
#include <cstdlib>

long long get_fibonacci_huge_naive(long long n, long long m) {
	if (n <= 1)
		return n;

	long long previous = 0;
	long long current = 1;

	for (long long i = 0; i < n - 1; ++i) {
		long long tmp_previous = previous;
		previous = current;
		current = tmp_previous + current;
	}

	return current % m;
}

int get_fibonacci_huge_fast(long long n, long long m) {
	std::vector<int> periodical;
	int period = 0;
	int previous = 0;
	int current = 1;
	periodical.push_back(0);
	periodical.push_back(1);
	while (true) {         // 寻找周期数列
		int tmp_previous = previous % m;
		previous = current % m;
		current = tmp_previous + current % m;
		periodical.push_back(current % m);

		int p_size = periodical.size();
		bool all_checked = false;
		if (p_size % 2 == 0) {                    //可能出现周期
			for (int i = 0; i < 3; i++) {  // 检查是否出现周期(只检查前3位)
				all_checked = true;
				if (periodical[i] != periodical[i + p_size / 2]) {
					all_checked = false;
					break;
				}
			}
		}
		if (all_checked) {  // 成功找到周期，跳出死循环
			period = p_size / 2;
			break;
		}
	}

	int idx = n % period;
	return periodical[idx];
}

void get_fibonacci_huge_test() {
	while (true) {
		int n = rand() % 100 + 1;
		int m = rand() % 500 + 2;
		std::cout << n << " " << m << '\n';
		long long res_naive = get_fibonacci_huge_naive(n, m);
		std::cout << res_naive << "\n";
		long long res_fast = get_fibonacci_huge_fast(n, m);
		std::cout << res_fast << "\n";
		if (res_naive == res_fast)
			std::cout << "OK" << '\n';
		else {
			break;
		}
	}

}

int main() {
	// get_fibonacci_huge_test();

	long long n, m;
	std::cin >> n >> m;
	std::cout << get_fibonacci_huge_fast(n, m) << '\n';

	return 0;
}
