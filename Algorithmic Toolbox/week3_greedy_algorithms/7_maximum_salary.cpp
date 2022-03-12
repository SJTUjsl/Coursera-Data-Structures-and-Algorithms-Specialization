#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
bool isBetter(string a, string b) {
	if(stoi(a + b) > stoi(b + a))
        return true;
    else
        return false;
}

string largest_number(vector<string> a) {
	//write your code here
	std::stringstream ret;
	while (a.size() > 0) {
		string max_digit = "0";
		int max_idx = 0;
		for (int i = 0; i < a.size(); ++i) {
			if (isBetter(a[i], max_digit)) {
				max_digit = a[i];
				max_idx = i;
			}
		}
		ret << max_digit;
		a.erase(a.begin() + max_idx);
	}
	string result;
	ret >> result;
	return result;

}

int main() {
	int n;
	std::cin >> n;
	vector<string> a(n);
	for (size_t i = 0; i < a.size(); i++) {
		std::cin >> a[i];
	}
	std::cout << largest_number(a);
}
