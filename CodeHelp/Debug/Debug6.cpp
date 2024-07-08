#include <iostream>
using namespace std;

int main(){
	int* ptr=0;
	int a = 5;
	ptr = &a;
	cout << *ptr << endl;
	return 0;
}