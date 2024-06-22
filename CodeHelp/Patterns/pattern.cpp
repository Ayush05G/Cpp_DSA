#include<iostream>
using namespace std;



int main() {

    //half pyramid
    int n;
    cout << "Enter the value of n ";
    cin >> n;

    //inverted numeric half pyramid 

    /*for(int row=0; row<n; row++) {
        for(int col=0; col< n-row; col++) {
            cout << (col+1) <<" ";
        }
        cout << endl;
    }*/

    //numeric half pyramid 
    //outer 
     /*for(int row=0; row<n; row++) {
    //inner 
         for(int col=0; col<row+1; col++) {
             cout << (col+1) << " ";
         }
         cout << endl;
     }*/

    //inverted hollow half pyramid 
     /*for(int row=0; row<n; row++) {
         for(int col=0; col<n-row; col++) {
             if(row == 0 || col == 0 || (row+col == n-1) ) {
                 cout << "* ";
             }
             else {
                 cout << "  ";
             }
         }
    //ye main bhul jata hu
         cout << endl;
     }*/

    /* for(int row=0; row<n; row++) {

        for(int col=0; col < row+1; col++) {

            if(row == 0 || row == n-1 || col == 0 || row == col) {
                cout << "* ";
             }
             else {
                cout << "  ";
             }}
             cout<<endl;
        }

              if(row == 0 || row ==  1 || row == n-1) {
        cout << "* ";
     }
     else {
         //middle rows
         if(col == 0 || col ==row) {
             cout << "* ";
         }
         else {
              //middle columns
             cout << "  ";
         }
     }
        }
         cout << endl;
     }*/
     /*
    //inverted pyramid
    //outer
     for(int row=0; row<n; row++) {
        for(int col=0; col < n-row; col++) {
             cout << "* ";
         }
         cout << endl;
     }
*/
    //outer
    // for(int row=0; row<n; row++) {
    //     //inner loops - columns
    //     for(int col =0; col < row+1; col++) {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }


    //hollow square
    // int n;
    // cout << "Enter length of side of square" << endl;
    // cin >> n;

    // //outer -> rows
    // for(int row=0; row<n; row++) {
    //     //inner -> cols
    //     for(int col=0; col<n; col++) {
    //         if(row == 0 || row == n-1 || col == 0 || col == n-1 ) 
    //             cout << "* ";
    //         else
    //             cout << "  ";
    //     }
    //     //ye main bhul jata hu
    //     cout << endl;
    // }




    //hollow rectangle
    // int length;
    // int width;
    // cout << "Enter length" << endl;
    // cin >> length;

    // cout << "Enter width " << endl;
    // cin >> width;

    // //outer
    // for(int row = 0; row < length; row = row + 1 ) {
    //     //inner 
    //     for(int col = 0; col < width; col = col + 1) {
    //         //first and last row me all stars
    //         if(row == 0 || row == length-1) {
    //             cout << "* ";
    //         }
    //         else {
    //             //middle rows
    //             if(col == 0 || col == width-1) {
    //                 cout << "* ";
    //             }
    //             else {
    //                 cout << "  ";
    //             }
    //         }
    //     }
    //     cout << endl;
    // }


    //square 
    // int side;
    // cout << "Enter length of side of square" << endl;
    // cin >> side;

    // for(int r=0; r < side; r++) {
    //     for(int c=0; c < side; c++) {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }


    //Rectangle
    // int length;
    // int width;
    // cout << "Enter length" << endl;
    // cin >> length;

    // cout << "Enter width " << endl;
    // cin >> width;

    // //outer
    // for(int row=0; row < length; row++) {
    //     //inner
    //     for(int col=0; col < width; col++) {
    //         //hr 1 column me 1 * print krna h 
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }



    //Square
    //totoal rows = 4;
    //every row -> 4 star

    //row -> outer
    //col -> inner

    //outer loop -> 4 rows
    // for(int row=0; row<4; row++) {
    //     //inner loop -> 4 star print
    //     //hr row me kya krna hai, vo inner loop bataega
    //     for(int col=0; col<4; col++) {
    //         //hr 1 single column me, 1 star rakha hai
    //         cout << "* ";
    //     }
    //     //4 star print karane k baad, next line me aata hu
    //     cout << endl;
    // }

        // for(int row=0; row<4; row++) {
       
        //     for(int col=0; col<4; col++) {
        //         cout << "* ";
        //     }
        //     cout << endl;
        // }




    return 0;
}