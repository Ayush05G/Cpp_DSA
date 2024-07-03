#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[] = {"","M","MM","MMM"};
        string first =ths[num/1000];
        string second=hrns[(num%1000)/100];
        string third=tens[(num%100)/10];
        string fourth=ones[(num%10)];
        return first+second+third+fourth;
}
};