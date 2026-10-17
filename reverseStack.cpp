#include<iostream>
#include<stack>
using namespace std;

void pushAtBottom(stack<int>& s, int val){
    // base case
    if(s.empty()){
        s.push(val);
        return;
    }

    int temp = s.top();
    s.pop();

    pushAtBottom(s, val);
    s.push(temp);
}

void reverseStack(stack<int> &s){
    if(s.empty()){
        return;
    }

    int top = s.top();
    s.pop();
    reverseStack(s);
    pushAtBottom(s, top);
}

int main(){
    stack<int> s;

    // Stack elements push करणे
    s.push(3);
    s.push(2);
    s.push(1);

    // Stack reverse करणे
    reverseStack(s);

    // Reversed stack print करणे
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
