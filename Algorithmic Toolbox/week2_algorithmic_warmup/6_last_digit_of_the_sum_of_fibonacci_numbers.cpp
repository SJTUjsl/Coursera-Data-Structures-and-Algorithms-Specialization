#include <iostream>
#include <cstdlib>
#include <vector>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int fibonacci_sum_fast(long long n) {
	std::vector<int> periodical;
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

	int idx = (n + 2) % 60;
	return (periodical[idx] + 9) % 10;
}

void fibonacci_sum_test(){
    while(true){
        int n = rand() % 1000;
        std::cout << n << '\n';
        int res_naive = fibonacci_sum_naive(n);
        int res_fast = fibonacci_sum_fast(n);
        if(res_naive == res_fast)
            std::cout << "OK\n";
        else{
            std::cout << res_naive << res_fast << '\n';
            break;
        }
    }
}

int main() {
    //fibonacci_sum_test();

    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n)<<'\n';


}
