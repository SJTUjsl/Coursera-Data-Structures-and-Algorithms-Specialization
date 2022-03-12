#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
	int start, end;
};

bool GreaterSort(Segment a, Segment b) { return (a.start < b.start); }

vector<int> optimal_points(vector<Segment> &segments) {
	vector<int> points;
	//write your code here
	std::sort(segments.begin(), segments.end(), GreaterSort); // sort leftwise

	for (size_t i = 0; i < segments.size(); ++i) {
		Segment current = segments[i];// the segment that include every valid point

		while (i < segments.size()-1 && segments[i + 1].start <= current.end) { // get another line into account
			if (current.start < segments[i + 1].start)// reduce the segment length
				current.start = segments[i + 1].start;
			if (current.end > segments[i + 1].end)
				current.end = segments[i + 1].end;
			i++;
		}
		points.push_back(current.end);
	}
	return points;
}

int main() {
	int n;
	std::cin >> n;
	vector<Segment> segments(n);
	for (size_t i = 0; i < segments.size(); ++i) {
		std::cin >> segments[i].start >> segments[i].end;
	}
	vector<int> points = optimal_points(segments);
	std::cout << points.size() << "\n";
	for (size_t i = 0; i < points.size(); ++i) {
		std::cout << points[i] << " ";
	}
}
