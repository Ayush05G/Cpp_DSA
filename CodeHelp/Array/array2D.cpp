#include<iostream>
#include<limits.h>
using namespace std;


bool search2DArray(int arr[][4], int rowSize, int colSize, int target) {

    for(int i=0; i<rowSize; i++) {
        for(int j=0; j<colSize; j++) {

            if(arr[i][j] == target) {
                return true;
            }

        }
    }
    //agar line 13 tak pohoch gye
    //iska matlab dono loop traverse kar chuke ho
    //iska matlab entire array traverse kr chuke ho
    //iska matlab entire array me target nahi mila
    //iska matlab target not found
    //iska matlab return false
    return false;
}

int findMinimumIn2DArray(int arr[][4], int rowSize, int colSize) {

    int minValue = INT_MAX;

    for(int i=0; i<rowSize; i++) {
        for(int j=0; j<colSize; j++) {
            minValue = min(arr[i][j], minValue);
        }
    }
    
    return minValue;

}

int findMaximumIn2DArray(int arr[][4], int rowSize, int colSize) {

    int maxAns = INT_MIN;

    for(int i=0; i<rowSize; i++) {
        for(int j=0; j<colSize; j++) {
            maxAns = max(arr[i][j], maxAns);
        }
    }
    //overall T.C -> O(rowSize*colSize)
    //overall S.c-> O(1) space

    return maxAns;

}

void printRowSum(int arr[][4], int rowSize, int colSize) {

    for(int i=0; i<rowSize; i++) {
        int sum = 0;
        //hr row k liye sum starting me 0 hai
        for(int j=0; j<colSize; j++) {
            sum = sum + arr[i][j];
        }
        //jab saare column k element add krliye hai
        //toh fer print krdo
        cout << sum << endl;
    }
    
}

void printColumnSum(int arr[][4], int rowSize, int colSize) {

    for(int col=0; col<colSize; col++) {
        //hr column k liye mere pass sum = 0 hona chahiye 
        int sum = 0;
        for(int row=0; row<rowSize; row++) {
            sum = sum + arr[row][col];
        }
        cout << sum << endl;
    }

}

void printDiagnolSum(int arr[][3], int rowSize, int colSize) {

    int sum = 0;
    
    for(int i=0; i<rowSize; i++) {
        sum = sum + arr[i][i];
    }
    
    cout << "Sum: " << sum << endl;



    // int sum = 0;
    // for(int i=0; i<rowSize; i++) {
    //     for(int j=0; j<colSize; j++) {
    //         if(i == j) {
    //             sum = sum + arr[i][j];
    //         }
    //     }
    // }
    // cout << "sum " << sum <<endl;
}

void transposeMatrix(int arr[][3], int rowSize, int colSize) {

    //same array me hi transpose karo
    for(int i=0; i<rowSize; i++) {
        for(int j=i; j<colSize; j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }

    //printing
    cout << "printint the transpose" << endl;
    for(int i=0; i<rowSize; i++) {
        for(int j=0; j<colSize; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }


    // int ans[100][100] = {0};

    // for(int i=0; i<rowSize; i++) {
    //     for(int j=0; j<colSize; j++) {
    //         ans[i][j] = arr[j][i];
    //     }
    // }

    
    // for(int i=0; i<rowSize; i++) {
    //     for(int j=0; j<colSize; j++) {
    //         cout << ans[i][j] << " ";
    //     }cout << endl;
    // }


}


int main() {

    int arr[3][3] = {
                    {10,11,12},
                    {20,21,22},
                    {30,31,32}
                    };
    int rowSize = 3;
    int colSize = 3;

    transposeMatrix(arr,rowSize, colSize);

    //printDiagnolSum(arr,rowSize,colSize);
    
    
    //printColumnSum(arr,rowSize,colSize);

    

    //printRowSum(arr,rowSize,colSize);


    // int maxAns = findMaximumIn2DArray(arr,rowSize,colSize);
    // cout << "max num: " << maxAns << endl;


    // int ans = findMinimumIn2DArray(arr,rowSize,colSize);
    // cout << ans << endl;




    //int target = 404;

    // bool ans = search2DArray(arr,rowSize,colSize,target);

    // cout << "ans is: " << ans << endl;











    //declaring 2D array
    //int arr[4][3];

    //initialise
    // int arr[3][3] = {
    //                 {10,20,100},
    //                 {30,40,200},
    //                 {50,60,300}
    //                 };
    // int rowSize=3;
    // int colSize=3;

    //diagnol matrix -> square matrix
    // for(int i=0; i<rowSize; i++) {
    //     cout << arr[i][i] << " ";
    // }

    // for(int r=0; r<rowSize; r++) {
    //     for(int c=0; c<colSize; c++) {
    //         if(r == c) {
    //             cout << arr[r][c] <<  " ";
    //         }
    //     }
    //     cout << endl;
    // }

    ///int arr[3][2] = {10,20,30,40,50,60};
    // int arr[3][2] = {10,20};

    //cout << arr[2][1] << endl;

    //traverse the entire array


    //row-wise
    // for(int rowIndex = 0; rowIndex<rowSize; rowIndex++) {
    //     for(int colIndex=0; colIndex<colSize; colIndex++) {
    //         cout << arr[rowIndex][colIndex] << " ";
    //     }
    //     cout << endl;
    // }

    //column wise
    // for(int col=0; col<colSize; col++) {
    //     for(int row=0; row<rowSize; row++) {
    //         cout << arr[row][col] << " ";
    //     }
    //     cout << endl;
    // } 


    //square -matrix
    // for(int r=0; r<rowSize; r++) {
    //     for(int c=0; c<colSize; c++) {
    //         cout << "Printing " << c << ", " << r << endl;
    //         cout << arr[c][r] << " ";
    //     }
    //     cout << endl;
    // }


    // int arr[2][3];
    // int rowSize = 2;
    // int colSize = 3;

    // //taking input -> row-wise
    // for(int i=0; i<rowSize; i++) {
    //     for(int j=0; j<colSize; j++) {
    //         cout << "Enter the value for (" << i << ", " <<j << ") : ";
    //         cin >> arr[i][j];
    //     }
    // }

    // cout << "Printing 2D array: " << endl;
    // //row-wise
    // for(int rowIndex = 0; rowIndex<rowSize; rowIndex++) {
    //     for(int colIndex=0; colIndex<colSize; colIndex++) {
    //         cout << arr[rowIndex][colIndex] << " ";
    //     }
    //     cout << endl;
    // }




    return 0;
}