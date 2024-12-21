#include <bits/stdc++.h>
using namespace std;


/*
Given an integer, convert it to a roman numeral.
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/

string intToRoman(int num) {
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[] = {"","M","MM","MMM"};
        
        return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
    }

int main(){
    int num;
    cin>>num;
    cout<<intToRoman(num)<<endl;
    return 0;
}
