#include<iostream>
#include<vector>
using namespace std;

class Stack{
    vector<int> vec;

    public:
        void push(int val){
            vec.push_back(val);
        }

        void pop(){
            vec.pop_back();
        }

        int top(){
            if(isEmpty()){
                cout<<"Stack is Empty.."<<endl;
                return -1;
            }

            int lastIdx = vec.size() - 1;
            return vec[lastIdx];
        }

        bool isEmpty(){
            return vec.size() == 0;
        }
};

int main(){
    Stack s1;

    s1.push(3);
    s1.push(2);
    s1.push(1);

    while(!s1.isEmpty()){
        cout<<s1.top()<< " ";
        s1.pop();
    }

    return 0;
}