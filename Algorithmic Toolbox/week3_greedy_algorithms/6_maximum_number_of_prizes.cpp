#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
    vector<int> summands;
    //write your code here
    int biggesst = 0;
    while(n > (biggesst + 1) * 2){
        biggesst++;
        summands.push_back(biggesst);
        n -= biggesst;
    }
    summands.push_back(n);
    return summands;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> summands = optimal_summands(n);
    std::cout << summands.size() << '\n';
    for (size_t i = 0; i < summands.size(); ++i) {
        std::cout << summands[i] << ' ';
    }
}
