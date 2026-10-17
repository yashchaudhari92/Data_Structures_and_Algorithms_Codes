#include<iostream>
#include<stack>
using namespace std;

class Queue {
    stack<int> s1;
    stack<int> s2;

public:
    void push(int data){
        // Move all elements from s1 to s2
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        // Push new element
        s2.push(data);

        // Move everything back to s1
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop(){
        if(s1.empty()){
            cout << "Queue is empty\n";
            return;
        }
        s1.pop();
    }

    int front(){
        if(s1.empty()){
            cout << "Queue is empty\n";
            return -1;
        }
        return s1.top();
    }

    bool empty(){
        return s1.empty();
    }
};

int main(){
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.front() << endl; // 10

    q.pop(); // removes 10
    cout << "Front after pop: " << q.front() << endl; // 20

    q.pop(); // removes 20
    cout << "Front after pop: " << q.front() << endl; // 30

    q.pop(); // removes 30
    q.pop(); // trying to pop empty queue

    return 0;
}
