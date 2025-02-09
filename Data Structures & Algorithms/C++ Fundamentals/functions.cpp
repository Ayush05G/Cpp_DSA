#include <iostream>
using namespace std;

//void -> returns nothing

// void sayMyName() {
//   cout << "babbar" << endl;
// }


//waf to calculate a to the power of b 
int calculatePower(int a, int b ) {
  ///a to the power b => a*a*a* --- b times
  int ans = 1;
  for(int i=1; i<=b; i++) {
    ans = ans * a;
  }
  return ans;
}

float calculateTotalSum(int a, int l, int n) {
  float ans = ((n)*(a+l))/2.0;
  return ans;
}

bool isPrime(int number) {

  for(int i=2; i<=(number-1); i++) {
    if(number % i == 0) {
      ///not prime
      return false;
    }
  }
  ///agar aap ayaha tk aagye ho
  //iska mtlab kisi se bhi remainder 0 nahi aaya 
  //iska matalab aap prime ho
  //ika mtlb return true;
  return true;

}

void printEvenInsideRange(int start, int end) {
  for(int i=start; i<=end; i++) {
    int n = i;
    if((n&1)) {
      cout << n  << endl;
    }
  }
}

float calculatePercentage(int sb1, int sb2, int sb3, int sb4, int sb5) {
  int sum = sb1 + sb2 + sb3 + sb4 + sb5;
  int totalMarks = 500;

  float percentage = (sum * 100.0)/totalMarks;
  return percentage;

}



int main() {

  int age = 15;
  int &demo = age;
  age++;
  cout << demo;
  // cout << "Total: " << calculatePercentage(95,95,98,100,95) << endl;
  // printEvenInsideRange(101,123);

  // bool ans = isPrime(2);
  // if(ans == true) {
  //   cout << "Prime" ;
  // }
  // else {
  //   cout << "Not prime";
  // }

  // float output = 9/2.0;
  // cout << output ;

  // float ans = calculateTotalSum(1,5,3);
  // cout << ans << endl;

  // int finalAns = calculatePower(2,10);
  // cout << finalAns << endl;

  //function call
  //5 -> arguements
  // printN_KaTable(15);

  //function use -> function call
  // sayMyName();

  // int number = 15;
  // int setBitCount = 0;

  // while(number != 0) {

  //   int lastbit = (number & 1);
  //   if(lastbit == 1) {
  //     setBitCount = setBitCount + 1;
  //   }
  //   //right shift
  //   number = number >> 1;
  // }
 
  // cout << "total set bits: " << setBitCount << endl;


  //cout << ((-10) >> 1) << endl;

  // int n = 110;
  // if(n&1) { 
  //   cout << "Odd num";
  // }
  // else {
  //   cout << "even number" << endl;
  // }


  // if( (n&1) == 0) {
  //   cout << "Even number" << endl;
  // }
  // else {
  //   cout << "Odd Number" << endl;
  // }

  return 0;
}


void printN_KaTable(int n) {
  for(int i=1; i<=10; i++) {
    cout << n*i << endl;
  }
}