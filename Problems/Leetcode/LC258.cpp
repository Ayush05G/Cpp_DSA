// Approach 1: Iterative approach to solve the problem(Self)
class Solution {
public:
    int addDigits(int num) {
        int sum=0;
        if(num/10==0){
            return num;
        }
        while(num/10!=0){
            sum=num%10;
            num=num/10;
            sum+=num;
            num=sum;

        }
        return sum;
        
    }
};

// Approach 2: Digital Root Formula
class Solution {
public:
    int addDigits(int num) {
         if (num == 0) { 
            return 0; 
        }
        // For all other numbers, the digital root is the remainder when the number
        // is divided by 9, with a special case when num is a multiple of 9.
        else {
        return 1 + (num - 1) % 9;
        }
    }
};