#include <iostream>
#include "algorithm.h" /// ALGORITHM_H -> defined now

using namespace std;

int main()
{
    int arr[] = {1, 2, 5, 2, 3};
    sort(arr, 5);
    return 0;
}

// g++ -o is used to make exe from .os
// g++ -c is used to make .os, from .cpp

// 1. Make .os of all .cpp files: "g++ -c a.cpp"
// 2. Link all .os and make executable: "g++ a.o b.o main.o -o my_program"