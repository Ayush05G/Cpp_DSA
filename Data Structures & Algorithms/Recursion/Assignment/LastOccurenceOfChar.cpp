#include <iostream>
#include <string>
using namespace std;

int LastIndex(string s, char p) {
    return LastIndexHelper(s, p, s.size() - 1);
}

int LastIndexHelper(string s, char p, int i) {
    if (i < 0)
        return -1;
    if (s[i] == p)
        return i;
    return LastIndexHelper(s, p, i - 1);
}