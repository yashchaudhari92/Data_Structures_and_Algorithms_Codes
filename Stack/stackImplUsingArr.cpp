// Implementation of Stack Using arrays

#include<iostream>
using namespace std;
#define SIZE 5

class Stack{
    int arr[SIZE];
    int top;

    public:
        Stack(){
            top = -1;
        }

        void push(int val){
            if(top == SIZE - 1){
                cout<<"Stack Overflow..";
                return;
            }

            arr[++top] = val;   // push at top
        }

        void pop(){
            if(top == -1){
                cout<<"Stack Underflow..";
                return;
            }

            top--;  // pop from stack
        }

        int peek(){
            if(top == -1){
                cout<<"Stack underflow or empty..";
                return -1;
            }

            return arr[top];
        }

        bool isEmpty(){
            return top == -1;
        }
};

int main(){
    Stack s1;

    s1.push(3);
    s1.push(2);
    s1.push(1);

    while(!s1.isEmpty()){
        cout<<s1.peek()<< " ";
        s1.pop();
    }

    return 0;
}