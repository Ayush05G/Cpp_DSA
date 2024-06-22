#include<iostream>
#include<set>
#include<unordered_set>
using namespace std;


int main() {

    set<int> st;

    st.insert(10);
    st.insert(15);
    st.insert(8);
    st.insert(4);

    if(st.count(155) == 1) {
        cout << "Found";
    }
    if(st.count(155) == 0) {
        cout << "not found";
    }

    if(st.find(155) != st.end() ) {
        cout << "Found";
    }
    else {
        cout << "Not found";
    }

    st.erase(st.begin(), st.end());
    cout << st.size() << endl;

    cout << st.size() << endl;
    st.clear();
    cout << st.size() << endl;

    if(st.empty()) {
        cout << "set is empty" << endl;
    }
    else {
        cout << "set is not empty" << endl;
    }


    //traverse
    set<int>::iterator it = st.begin();

    while(it != st.end() ) {
        cout << *it << " ";
        it++;
    }




    return 0;
}