#include <iostream>
#include <cstdlib>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

int gcd_fast(int a, int b) {
    int gcd = 0;
    if(a == 0 || b == 0)
        return 1;

    while(a != 0 && b != 0){
        if(a > b) a = a % b;
        else b = b % a;
    }

    if(a == 0) gcd = b;
    else gcd = a;

    return gcd;

}

long long lcm_fast(int a, int b) {
    int gcd = gcd_fast(a, b);
    long long lcm = (long long)a * b / gcd;
    return lcm; 
}

void lcm_test() {
    while(true){
        int a = rand() % 10000;
        int b = rand() % 10000;
        std::cout << "a: " << a << "  b: " << b << '\n';
        long long res_naive = lcm_naive(a,b);
        long long res_fast = lcm_fast(a,b);
        if(res_naive == res_fast)
            std::cout << "OK" << '\n';
        else{
            std::cout << res_naive << " " << res_fast << '\n';
            break;
        }
    }
}

int main() {
    // lcm_test();

    int a, b;
    std::cin >> a >> b;
    std::cout << lcm_fast(a, b) << std::endl;
    return 0;
}
