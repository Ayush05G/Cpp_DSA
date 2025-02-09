#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
	if (intervals.empty()) {
		return vector<vector<int>>();
	}

	sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
		return a[0] < b[0];
	});

	stack<vector<int>> mergedStack;
	mergedStack.push(intervals[0]);

	for (int i = 1; i < intervals.size(); i++) {
		vector<int> current = intervals[i];
		vector<int>& top = mergedStack.top();
		if (current[0] <= top[1]) {
			top[1] = max(top[1], current[1]);
		} else {
			mergedStack.push(current);
		}
	}
	vector<vector<int>> mergedIntervals;
	while (!mergedStack.empty()) {
		mergedIntervals.insert(mergedIntervals.begin(), mergedStack.top());
		mergedStack.pop();
	}

	return mergedIntervals;
}

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> mergedIntervals = overlappedInterval(intervals);
    for (vector<int>& interval : mergedIntervals) {
        cout << interval[0] << " " << interval[1] << endl;
    }
    return 0;
}