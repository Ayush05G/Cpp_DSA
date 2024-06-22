#include<iostream>
using namespace std;


int getLength(char arr[], int size) {

    int count = 0;

    for(int index=0; index<size; index++) {
        if(arr[index] == '\0') {
            break;
        }
        else {
            count++;
        }
    }

    // int index = 0;
    // while(arr[index] != '\0') {
    //     //jab tak array me null character nahi milta
    //     //tab tak increment karo
    //     //and aage badhi
    //     count++;
    //     index++;
    // }
    //return kardo count
    return count;

}
    
//original char -> '@'
//newChar -> ' '
void replaceCharacter(char originalChar, char newChar, char arr[], int size) {
    for(int i=0; i<size; i++) {
        if(arr[i] == originalChar) {
            arr[i] = newChar;
        }
    }
} 


void convertIntoUpperCase(char arr[], int n) {
    int len = getLength(arr,n);
    for(int i=0; i<len; i++) {
        
        char ch = arr[i];
        //if letter is a lowercase letter
        //then only convert it
        if(ch >='a' && ch<='z') {
            ch  = ch -'a' + 'A';
        }    
        arr[i] = ch;
    }
}

void convertIntoLowerCase(char arr[], int n) {
    int len = getLength(arr,n);
    for(int i=0; i<len; i++) {
        
        char ch = arr[i];
        //if letter is a lowercase letter
        //then only convert it
        if(ch >='A' && ch<='Z') {
            ch  = ch -'A' + 'a';
        }    
        arr[i] = ch;
    }
}


void reverseCharArray(char arr[], int n) {
    int len = getLength(arr,n);

    int i = 0;
    int j = len-1;

    while(i <= j) {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

bool checkPalindrome(char arr[], int n) {
    int len = getLength(arr,n);
    int i=0;
    int j=len-1;

    while(i <= j) {
        if(arr[i] == arr[j]) {
            i++;
            j--;
        }
        else {
            //not a palindrome
            return false;
        }
    }
    //agar main yha tk aagya
    //iska maltlab saaare char check ho chuke h
    //and different character nahi mila
    //iska matlab valid palindrome hai
    //iska mtalb return truel
    return true;
}

int main() {

    char arr1[100];
    cout << "Enter the input" << endl;
    cin >> arr1;

    char arr2[100];
    cout << "Enter the input" << endl;
    cin >> arr2;

    //cout << strlen(arr1) << endl;
    //cout << strcat(arr1,arr2) << endl;
    


    // char arr[1000];
    // cin >> arr;

    // cout << "Palindomr or not: " << checkPalindrome(arr,1000) << endl;

    // cout << "before " << arr << endl;
    
    // reverseCharArray(arr,1000);

    // cout << "after " << arr << endl;






    //convertIntoLowerCase(arr,1000);
    //convertIntoUpperCase(arr,1000);
    //replaceCharacter('@', ' ', arr, 1000);
    //cout << arr << endl;
    //cout << getLength(arr,1000) << endl;





    // char arr[100];

    // cout << "Enter input" << endl;
    // //cin >> arr;
    // cin.getline(arr, 80, '.'); 
    // cout << endl << arr << endl;



    // //creation
    // char arr[100];

    // cout << "Enter your name" << endl;
    // //input
    // //cin >> arr;
    // cin.getline(arr, 100);
    // //print
    // cout << "Your name is: " << arr << endl;
    // cout << arr[0] << "-> " << (int)arr[0] << endl;
    // cout << arr[1] << "-> " << (int)arr[1] << endl;
    // cout << arr[2] <<"-> " << (int)arr[2] << endl;
    // cout << arr[3] << "-> " << (int)arr[3] << endl;
    // cout << arr[4] << "-> " << (int)arr[4] << endl;
    //cout << arr[5] <<"-> " << (int)arr[5] << endl;







    return 0;
}