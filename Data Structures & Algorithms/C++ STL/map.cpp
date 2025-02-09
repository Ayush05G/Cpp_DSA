#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main() {

    map<int,string> table;

    table.insert(make_pair(3,"Love"));

    table.insert(make_pair(1,"Anita"));

    table.insert(make_pair(2,"Babita"));



    // //creation
    // map<string, string> table;

    // //insertion
    // table["in"] = "India";
    // table.insert(make_pair("en", "England"));

    // pair<string, string> p;
    // p.first = "br";
    // p.second = "brazil";
    // table.insert(p);

    // cout << table.size() << endl;

    // if(table.count("im") == 0) {
    //     cout << "Key not found" << endl;
    // }
    // if(table.count("im") == 1) {
    //     cout << "key found" << endl;
    // }

    // if(table.find("im") != table.end() ) {
    //     cout << "Key Found" << endl;
    // }
    // else {
    //     cout << "Key not found" << endl;
    // }


    // table.erase(table.begin(), table.end());
    // cout << table.size() << endl;

    map<int,string>::iterator it = table.begin();

    while(it != table.end()) {
        pair<int,string> p = *it;
        cout << p.first << " " << p.second << endl;
        it++;
    }

    // cout << table.at("in") << endl;
    // //table.at("in") = "india2";
    // table["in"] = "India3";
    // cout << table.at("in") << endl;
    // cout << table.size() << endl;
    // table.clear();
    // cout << table.size() << endl;

    // if(table.empty() == true) {
    //     cout << "map is empty" << endl;
    // }
    // else {
    //     cout << "map is not empty" << endl;
    // }











    return 0;
}