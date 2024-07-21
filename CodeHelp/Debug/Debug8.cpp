#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int start, int mid, int end) {
    int left[mid - start + 1];
    int right[end - mid];
    for (int i = 0; i <= mid - start; i++) {
        left[i] = arr[start + i];
    }
    for (int j = 0; j < end - mid; j++) {
        right[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0, k = start;
    while (i <= mid - start || j < end - mid) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i <= mid - start) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < end - mid) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }
    int mid = (start + end) / 2;
    merge_sort(arr, start, mid-1);
    merge_sort(arr, mid+1, end);
    merge(arr, start, mid, end);
}


int ceilSearch(int arr[], int low, int high, int x) {
	int mid;
	if (x < arr[low])
		return low;
	if (x >= arr[high])
		return -1;
	mid = (low + high) / 2;
	if (arr[mid] == x)
		return mid;
	else if (arr[mid] < x) {
		if (mid + 1 <= high && x <= arr[mid + 1])
			return mid + 1;
		else
			return ceilSearch(arr, mid + 1, high, x);
	}
	else {
		if (mid - 1 >= low && x > arr[mid - 1])
			return mid;
		else
			return ceilSearch(arr, low, mid - 1, x);
	}
}


void print(int** board, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << board[i][j] << " ";
        }
        cout<<endl;
    }
    cout << endl;
}

bool check_position(int** board, int col, int row, int n){
    for(int j=0; j<n; j++){
        if(board[row][j]) return false;
    }
    for(int i=0; i<n; i++){
        if(board[i][col]) return false;
    }
    for(int i=0; i<n; i++){
        if((row+col-i)>=n || (row+col-i<0)) continue;
        if(board[i][row+col-i]) return false;
    }
    for(int i=0; i<n; i++){
        if((i-row+col)>=n || (i-row+col<0)) continue;
        if(board[i][i-row+col]) return false;
    }
    return true;
}

bool backtracing(int** board, int n, int row){
    if(row > n){
        print(board,n);
        return true;
    }
    for(int j=0; j<n; j++){
        if(check_position(board,j,row,n)){
            board[row][j] = 1;
            backtracing(board, n, row+1);
            board[row][j] = 0;
        }
    }
}

void placeNQueens(int n){
    int** board = new int*[n];
    for(int i=0; i<n; i++){
        board[i] = new int[n];
        for(int j=0; j<n; j++){
            board[i][j] = 0;
        }
    }
    backtracing(board, n, 0);
}


void print(bool** visited, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << visited[i][j] << " ";
        }
    }
    cout << endl;
}

void solve(int maze[][20], bool** visited, int row, int col, int n){
    if(row>=n || col>=n || row < 0 || col < 0) return; 
    if(!(!visited[row][col] && maze[row][col])) return;
    visited[row][col] = true;
    if(row==n-1 && col == n-1){
        print(visited, n);
    }
    solve(maze,visited,row,col+1,n);
    solve(maze,visited,row,col-1,n);
    solve(maze,visited,row+1,col,n);
    solve(maze,visited,row-1,col,n);
    visited[row][col] = false;
}

void ratInAMaze(int maze[][20], int n){
	bool** visited = new bool*[n];
    for(int i=0; i<n; i++){
        visited[i] = new bool[n];
        for(int j=0; j<n; j++){
            visited[i][j] = false;
        }
    }
    solve(maze, visited, 0, 0, n);
}


int power(int x, int n){
    if(n == 0) return 1;
    if(x == 0) return 0;
    int temp = power(x, n/2);
    if(n % 2==0){
        return temp*temp;
    } else{
        return temp*temp*x;
    }
}

int main() {
    // int arr[] = {12, 11, 13, 5, 6, 7};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // merge_sort(arr, 0, n-1);
    // for (int i = 0; i < n; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // int arr[] = {1, 2, 8, 10, 10, 12, 19};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // int x = 5;
    // int index = ceilSearch(arr, 0, n-1, x);
    // if(index == -1){
    //     cout << "Ceil of " << x << " doesn't exist in the array" << endl;
    // } else{
    //     cout << "Ceil of " << x << " is " <<index<< endl;
    // }

    placeNQueens(4);

    // int maze[20][20] = {{1, 0, 0, 0},
    //                     {1, 1, 0, 1},
    //                     {0, 1, 0, 0},
    //                     {1, 1, 1, 1}};
    // ratInAMaze(maze, 4);

    // int result=power(2, 3);
    // cout << result << endl;

    return 0;
}