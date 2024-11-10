#include <bits/stdc++.h>
using namespace std;

/*k closest points to the origin using a priority queue*/
vector<pair<int, int>> kClosestPoints(vector<pair<int, int>> points, int n, int k)
{
    vector<pair<int, int>> ans;
    priority_queue<int, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p;

    for (int i = 0; i < n; i++)
    {
        int distance = points[i].first * points[i].first + points[i].second * points[i].second;
        p.push({distance, {points[i].first, points[i].second}});
    }
    while (k--)
    {
        auto x = p.top();
        ans.push_back({x.second.first, x.second.second});
                p.pop();
    }
    return ans;
}

int main()
{
    vector<pair<int, int>> points = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
    int n = points.size();
    int k = 2;
    vector<pair<int, int>> ans = kClosestPoints(points, n, k);
    for (auto x : ans)
    {
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}