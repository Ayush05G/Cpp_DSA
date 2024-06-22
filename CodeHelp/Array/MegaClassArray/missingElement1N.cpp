// Assignment: Missing Elements From An Array With Duplicates
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    vector<int> v = {1, 3, 5, 3, 4}; // 0 -> 4
    v.insert(v.begin(), 737);        // 0 -> 5

    // 737 -> 0 .. no work
    // 1 -> 1
    // 3 -> 2

    // visting with -1
    for (int i = 1; i < v.size(); i++)
    {
        int index = abs(v[i]);
        if (v[index] > 0)
        {
            v[index] *= -1;
        }
    }

    // for (int i = 1; i < v.size(); i++)
    // {
    //     cout << v[i] << " ";
    // }
    // cout << endl;
    int missing = -1;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] > 0)
        {
            missing = i;
            break;
        }
    }
    cout << "Missing: " << missing << endl;
    return 0;
}