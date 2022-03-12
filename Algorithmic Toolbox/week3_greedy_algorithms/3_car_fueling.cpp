#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
	// write your code here
	int refuel = 0;
	int current = 0;// initial position
	int next = 0;
	int idx = 0;
	while (idx < stops.size() && dist - current > tank) {
		while (idx < stops.size() && stops[idx] - current <= tank) { // get as far as we can
			next = stops[idx];
			idx++;
		}
		if (current == next)// impossible(in the middle)
			return -1;
		current = next; // make the move
		refuel += 1;

		if (idx == stops.size() && dist - current > tank)// out of fuel just near destination
			return -1;
	}
	return refuel;
}


int main() {
	int d = 0;
	cin >> d;
	int m = 0;
	cin >> m;
	int n = 0;
	cin >> n;

	vector<int> stops(n);
	for (size_t i = 0; i < n; ++i)
		cin >> stops.at(i);

	cout << compute_min_refills(d, m, stops) << "\n";

	return 0;
}
