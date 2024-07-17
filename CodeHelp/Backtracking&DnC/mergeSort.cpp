#include <iostream>
#include<vector>
using namespace std;

// void mergeSortedArrays(int arr[], int sizeArr, int brr[], int sizeBrr, vector<int> &ans) {

//   int i = 0;
//   int j = 0;
//   // i-> arr;
//   //j -> brr;

//   //jab tak i and j arrays k bounds k andar hai
//   while( i < sizeArr && j < sizeBrr) {
//     if(arr[i] < brr[j]) {
//       ans.push_back(arr[i]);
//       i++;
//     }
//     else {
//       ans.push_back(brr[j]);
//       j++;
//     }
//   }

//   //agar main yaha tk aagya 
//   //toh 2 cases ho skte h 
//   //1 case -> arr me still elements bache hai
//   while(i < sizeArr) {
//     ans.push_back(arr[i]);
//     i++;
//   }
//   //2 case -> brr me still elements bache hai
//   while(j < sizeBrr) {
//     ans.push_back(brr[j]);
//     j++;
//   }

// }

void merge(int arr[], int s, int e, int mid) {

  //create left and right arrays
  int leftLength = mid-s+1;
  int rightLength = e - mid;
  
  int *leftArr = new int[leftLength];
  int *rightArr = new int[rightLength];

  //fill or copy the left and right arrays 
  ///copy original array -> values
  //original array ka starting index
  int index = s;
  //copying into left array
  for(int i=0; i<leftLength; i++) {
    leftArr[i] = arr[index];
    index++;
  }
  //copying into right array
  index = mid+1;
  for(int i=0; i<rightLength; i++) {
    rightArr[i] = arr[index];
    index++;
  }

  //merge logic
  int i = 0;
  int j = 0;
  int mainArrayIndex = s;

  while(i < leftLength && j < rightLength) {
    if(leftArr[i] < rightArr[j]) {
      arr[mainArrayIndex] = leftArr[i];
      i++;
      mainArrayIndex++;
    }
    else {
      arr[mainArrayIndex] = rightArr[j];
      j++;
      mainArrayIndex++;
    }
  }

  ///I have to handle the 2 cases discussed above in Merge 2 sorted arrays wala question

  while(i < leftLength) {
     arr[mainArrayIndex] = leftArr[i];
      i++;
      mainArrayIndex++;
  }

  while(j < rightLength) {
    arr[mainArrayIndex] = rightArr[j];
      j++;
      mainArrayIndex++;
  }

  //delete heap memory 
  delete[] leftArr;
  delete[] rightArr;

}

void mergeSort(int arr[], int s, int e) {
  //base case
  if(s >= e) {
    return;
  }
  int mid = (s+e)/2;
  //left part recursion se solve karwao 
  mergeSort(arr,s,mid);
  //right part recursion se solve karwao
  mergeSort(arr,mid+1, e);
  //dono parts ko merge kardo
  merge(arr,s,e,mid);
}

int main() {
  int arr[] = {10,80,110,90,50,30,40,20};
  int size = 8;
  int s = 0;
  int e = size - 1;

  cout << "Before: " << endl;
  for(int i=0; i<size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  mergeSort(arr,s,e);

  //printing entire array
  cout << "After: " << endl;
  for(int i=0; i<size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  


  // int arr[] = {10,30,50,70};
  // int sizeArr = 4;

  // int brr[] = {20,40,60,80,90,100};
  // int sizeBrr = 6;

  // vector<int> ans;
  // mergeSortedArrays(arr,sizeArr, brr, sizeBrr, ans);
  // //printing ans
  // for(int num: ans) {
  //   cout << num << " ";
  // }

  return 0;
}