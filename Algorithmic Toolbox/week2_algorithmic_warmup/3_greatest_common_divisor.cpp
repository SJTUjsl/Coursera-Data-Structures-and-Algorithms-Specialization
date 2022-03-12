#include <iostream>
#include <cstdlib>

int gcd_naive(int a, int b) {
    int current_gcd = 1;
    for (int d = 2; d <= a && d <= b; d++) {
      if (a % d == 0 && b % d == 0) {
        if (d > current_gcd) {
          current_gcd = d;
        }
      }
    }
    return current_gcd;
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

void gcd_test() {
    while(true){
        int a = rand() % 1000000;
        int b = rand() % 1000000;
        std::cout << "a: " << a << "  b: " << b << '\n';
        if(gcd_naive(a,b) == gcd_fast(a,b))
            std::cout << "OK" << '\n';
        else{
            std::cout << gcd_naive(a,b) << " " << gcd_fast(a,b) << '\n';
            break;
        }
    }
}

int main() {

    //gcd_test();

    int a, b;
    std::cin >> a >> b;
    std::cout << gcd_fast(a, b) << std::endl;
    return 0;
}
