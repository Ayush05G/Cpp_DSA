#include <bits/stdc++.h>
using namespace std;

void kthSmallest(vector<int>& v, int N, int K)
{
	priority_queue<int> heap1;
	for (int i = 0; i < N; ++i) {
		heap1.push(v[i]);
		if (heap1.size() > K) {
			heap1.pop();
		}
	}
	cout << heap1.top() << endl;
}

int main()
{
    int N = 6, K = 3;
    vector<int> v = {7, 10, 4, 3, 20, 15};
    kthSmallest(v, N, K);
    return 0;
}