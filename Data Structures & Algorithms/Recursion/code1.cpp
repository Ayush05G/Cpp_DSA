#include<iostream>
using namespace std;

int getSum(int n) {
    //base case
    if(n == 1) 
        return 1;
    //recursive relation
    //sum(n) = sum(n-1) + n;
    int ans = getSum(n-1) + n;
    return ans;
    //processing
}

int fib(int n) {
    if(n == 0 || n == 1) 
        return n;
    int ans = fib(n-1) + fib(n-2);
    return ans; 
}


// int fib(int n) {
//    //base case
//    if(n == 0 || n == 1) {
//     return n;
//    }
//    //recursive relation
//    //fib(n) = fib(n-1) + fib(n-2);
//    int ans = fib(n-1) + fib(n-2);
//    return ans;
//    //processing  
// }


int pow(int n) {
    //base case
    if( n == 0) {
        return 1;
    }
    //recursive relation 
    //pow(n) = 2 * pow(n-1);
    int recKaAns = pow(n-1);
    int finalAns = 2 * recKaAns;
    return finalAns;
    //processing 
}



// print counting from n to 1 
void printCounting(int n) {
    //base case
    if(n == 0) {
        return;
    } 
    
    //processing
    cout << n << " "; 
    //recursive call 
    printCounting(n-1);
}



int getFactorial(int n) {
    //base case - mandatory
    if(n == 0 || n == 1) {
        return 1;
    }
    //recursive call - mandatory
    //fact(n) = n * fact(n-1);
    //recursion -> fact(n-1);
    int recursionKaAns = getFactorial(n-1);
    int finalAns = n * recursionKaAns;
    return finalAns;
    //processing - optional 
}

int main() {
    cout << getSum(5)<<endl;
    //cout << fib(9) << endl;
    //cout << pow(10);
    // printCounting(5);

    // int n;
    // cout << "Enter the value of n: " ;
    // cin >> n;

    // int ans = getFactorial(n);
    // cout << "Factorial of " << n << " is: " << ans << endl;





    return 0;
}