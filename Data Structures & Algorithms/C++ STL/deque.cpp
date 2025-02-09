#include<iostream>
#include<queue>
using namespace std;

int main() {
    
    //creation
    deque<int> dq;

    //insertion
    dq.push_back(10);
    //10
    dq.push_back(20);
    //10,20
    dq.push_back(40);
    //10,20,40
    dq.push_front(100);
    //100,10,20,40;
    dq.push_front(200);
    //200,100,10,20,40
    dq.push_front(300);
    //300,200,100,10,20,40

    dq.pop_front();
    //200,100,10,20,40
    dq.pop_back();
    //200,100,10,20
    cout << dq.size() << endl;
    dq.erase(dq.begin(), dq.end());
    cout << dq.size() << endl;

    // cout << dq.size() << endl;
    // dq.clear();
    // // dq is empty
    // cout << dq.size() << endl;

    // dq.insert(dq.begin(),101);
    // //101
    // cout << dq[0] << endl;

    //cout << dq.at(3) << endl;

    // deque<int>::iterator it = dq.begin();

    // while(it != dq.end()) {
    //     cout << *it << " ";
    //     it++;
    // }


    // cout << dq.size() << endl;
    // cout << dq.front() << endl;
    // cout << dq.back() << endl;

    // if(dq.empty() ==true) {
    //     cout << "Deque is empty" << endl;
    // }
    // else {
    //     cout << "deque is not empty" << endl;
    // }


    return 0;
}