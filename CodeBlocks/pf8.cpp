#include <iostream>
#include <climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    int min_so_far = INT_MAX;
    int max_so_far = INT_MIN;
    int no;
    for (int i = 0; i <n; i++)
    {cin>>no;
    if(no<min_so_far){
        min_so_far=no;
    }
    if(no>max_so_far){
        max_so_far=no;
    }
    }
    cout<<"Max no."<<max_so_far<<endl;
    cout<<"Min no."<<min_so_far<<endl;
    
return 0;
}
