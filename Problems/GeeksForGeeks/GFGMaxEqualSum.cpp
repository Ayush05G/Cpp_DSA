//Back-end complete function Template for C++

class Solution{
public:
    //Function to find maximum sum among three arrays.
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        int sum1=0,sum2=0,sum3=0;

        //Calculating sum of elements in each array.
        sum1=accumulate(S1.begin(),S1.end(),0);
        sum2=accumulate(S2.begin(),S2.end(),0);
        sum3=accumulate(S3.begin(),S3.end(),0);

        int top1=0,top2=0,top3=0;

        //Loop until the sums of all arrays are equal.
        while(true){
            //If any of the arrays have reached its end,
            //no equal sum can be found.
            if(top1==N1 or top2==N2 or top3==N3){
                return 0;
            }

            //If sums of all arrays are equal,
            //return the equal sum.
            if(sum1==sum2 and sum2==sum3){
                return sum1;
            }

            //If sum1 is largest, subtract the top element of S1
            //from sum1 and move to next element in S1.
            //Repeat the process until sum1 is smaller than other sums.
            if(sum1>=sum2 and sum1>=sum3){
                sum1-=S1[top1++];
            }

            //If sum2 is largest, subtract the top element of S2
            //from sum2 and move to next element in S2.
            //Repeat the process until sum2 is smaller than other sums.
            else if(sum2>=sum1 and sum2>=sum3){
                sum2-=S2[top2++];
            }

            //If sum3 is largest, subtract the top element of S3
            //from sum3 and move to next element in S3.
            //Repeat the process until sum3 is smaller than other sums.
            else if(sum3>=sum1 and sum3>=sum2){
                sum3-=S3[top3++];
            }
        }
        return 0;
    }
};
