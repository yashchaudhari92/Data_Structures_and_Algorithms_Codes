// // Reverse a string using a stack

// we know stack is work on LIFO principle, so we'll:
// 1. insert indivisual element into a stack from starting of a string.
// 2. keep out the element from the stack ans add in another ans string.

#include<iostream>
#include<string>
#include<stack>
using namespace std;

string reverseString(string str){

    string ans;
    stack<char>s;

    for(int i=0; i<str.size(); i++){
        char ch = str[i];
        s.push(ch);
    }

    while(!s.empty()){
        char top = s.top();
        ans += top;
        s.pop();
    }

    return ans;

}

int main(){
    string s;

    getline(cin, s);

    cout<<"Reverse string: "<<reverseString(s)<<endl;

    return 0;
}