#include<iostream>
#include<queue>
using namespace std;

int main() {

    //min-heap -> Minimum Value -> Highest Priority
    priority_queue<int,vector<int>, greater<int> > pq;

    pq.push(100);
    //100
    pq.push(50);
    //50,100
    pq.push(75);
    //50,75,100

    cout << pq.top() << endl;
    pq.pop();
    //75,100
    cout << pq.top() << endl;
    pq.pop();
    //100




    //creation
    // priority_queue<int> pq;
    // //max-heap -> maximum value -> Highest Priority

    // pq.push(10);
    // //10
    // pq.push(25);
    // //25,10
    // pq.push(55);
    // //55,25,10
    // pq.push(21);
    // //55,25,21,10

    // //top element -> Highest priority element
    // cout << pq.top() << endl;
    // //55
    // pq.pop();
    // //highest priority elemnet -> pop
    // //i.e -> 55 ko pop krdia 
    // //25,21,10;
    // cout << pq.top() << endl;
    // pq.pop();
    // //25 pop hojaega
    // //21,10;
    // cout << pq.top() << endl;

    // cout << pq.size() << endl;

    // if(pq.empty() == true) {
    //     cout << "PQ is empty" << endl;
    // }
    // else {
    //     cout << "PQ is not empty" << endl;
    // }



    return 0;
}