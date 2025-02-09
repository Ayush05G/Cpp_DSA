#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<int, int> desk_map; // roll_no, desk_no

    // insertion
    desk_map[1] = 53; // desk_map ki 1 key par, 53 desk no assign kr diya
    desk_map[2] = 54;
    desk_map[3] = 55;

    desk_map[2] = 57; // reassign, qki key = 2 was already there.

    // iterate
    // I have to iterate over 3 entries
    // for loop
    // map me iterate krne ke liye, make an iterator
    unordered_map<int, int>::iterator it; // syntax to acces each entry in map
    for (it = desk_map.begin(); it != desk_map.end(); it++)
    {
        int key = it->first; // syntax
        int value = it->second;
        cout << "Key: " << key << " " << "Value: " << value << endl;
    }

    // find? // table/map bht fast (Avg case comp) O(1)
    // 2 is key
    if (desk_map.find(2) != desk_map.end()) // syntax
    {
        // found
        int value = desk_map[2];
        cout << "Found: " << value << endl;
    }
    else
    {
        // not found
        cout << "Not Found" << endl;
    }

    // deletion
    // key se hi hota hai
    desk_map.erase(2);

    cout << "after erase" << endl;// syntax to acces each entry in map
    for (it = desk_map.begin(); it != desk_map.end(); it++)
    {
        int key = it->first; // syntax
        int value = it->second;
        cout << "Key: " << key << " " << "Value: " << value << endl;
    }

    cout << "Find 2 again" << endl;
    if (desk_map.find(2) != desk_map.end()) // syntax
    {
        // found
        int value = desk_map[2];
        cout << "Found: " << value << endl;
    }
    else
    {
        // not found
        cout << "Not Found" << endl;
    }
    return 0;
}