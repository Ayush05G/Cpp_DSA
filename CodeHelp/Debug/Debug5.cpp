#include <iostream>
#include <algorithm>
#include<cmath>
#include<limits.h>
#include <vector>
#include<string>
using namespace std;

int mystoi(string s) {
        int len = s.size();
        int num = 0;
        int i=0;
        while(i<len && s[i] == ' '){
            i++;
        }
        bool negative = s[i] == '-';
        negative == true ? i++ : i;
        while(i < len && s[i] >= '0' && s[i] <= '9'){
            num = num*10 + s[i]-'0';
            i++;
        }
        num = negative ? -num : num;
        num = (num > INT_MAX) ? INT_MAX : num;
        num = (num < INT_MIN) ? INT_MIN : num;
        return int(num);
    }

    string intToRoman(int num) {
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[] = {"","M","MM"};
        
        return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[(num%10)];
}

    int main(){
        // string s;
        // getline(cin, s);
        // int converted=mystoi(s);
        // cout<<converted;
        int num;
        cin>>num;
        string roman=intToRoman(num);
        cout<<roman;
        return 0;
    }