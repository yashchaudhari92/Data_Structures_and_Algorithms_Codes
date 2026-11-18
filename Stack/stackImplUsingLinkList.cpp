// Implementation of Stack using linked list.

// we are going to use push_front here:

// 1. Stack Push() = ll.push_front()
// 2. Stack pop() = ll.pop_front()
// 3. Stack top() = ll.head->data



// Code :- Without STL

#include<iostream>
using namespace std;

template<class T>
class Node{
    public:
        T data;
        Node* next;

        Node(T val){
            data = val;
            next = nullptr;
        }

};

template<class T>
class Stack{
    public:
        Node<T>* head;

        Stack(){
            head = nullptr;
        }

        void push(T val){

            // push_front()

            Node<T>* newNode = new Node<T>(val);

            if(head == nullptr){
                head = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            }
        }

        void pop(){

            // pop_front()

            Node<T>* temp = head;
            head = head->next;
            temp->next = nullptr;
            delete temp;

        }

        T top(){
            return head->data;
        }

        bool isEmpty(){
            return head == nullptr;
        }

};


// Code :- Using STL

// #include<iostream>
// #include<list>
// using namespace std;

// template<class T>
// class Stack{
//     list<T> ll;

//     public:
//         void push(T val){
//             ll.push_front(val);
//         }

//         void pop(){
//             if(isEmpty()){
//                 cout<<"Stack Underflow"<<endl;
//                 return;
//             }

//             ll.pop_front();
//         }

//         T top(){
//             if(isEmpty()){
//                 cout << "Stack is Empty" << endl;
//                 return T{};
//             }

//             return ll.front();
//         }

//         bool isEmpty(){
//             return ll.size() == 0;
//         }

// };

int main(){
    Stack<int> s1;

    s1.push(1);
    s1.push(2);
    s1.push(3);

    while(!s1.isEmpty()){
        cout<<s1.top()<< " ";
        s1.pop();
    }

    return 0;
}