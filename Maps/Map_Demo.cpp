#include<iostream>
#include<map>
#include<string>
using namespace std;


int main(){
    map<int, string> m;

    m[101] = "Rahul";
    m[102] = "Yash";
    m[110] = "Sunny";

    cout<<m[101]<< " "<< endl;

    cout<<m.count(101);

    for(auto it: m){
        cout<<"Key = " << it.first << "," << "Value = " << it.second << endl;
    }

    return 0;
}