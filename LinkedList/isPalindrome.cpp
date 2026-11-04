// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

// Example:-

// input:
// 1 -> 2 -> 2 -> 1

// output: 
// true


// We'll solve it using : slow & fast + reverse

// 1. Find the middle node using slow and fast pointers
// 2. Reverse the second half, starting from slow.
// 3. Compare both halves, left->data == right->data return true.
// 4. else return false.


// Code :- 

#include<iostream>
using namespace std;

class Node {
    int data;
    Node* next;

public:
    Node(int val) {
        data = val;
        next = nullptr;
    }

    friend class List;
};

class List {
    Node* head;
    Node* tail;

public:
    List() {
        head = nullptr;
        tail = nullptr;
    }

    void push_back(int val) {
        Node* newNode = new Node(val);

        if(head == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    bool isPalindrome(){
        Node* slow = head;
        Node* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;          // here slow returns the mid of linked list.
            fast = fast->next->next;
        }

        // Reverse the second half from slow(mid).

        Node* prev = nullptr;
        Node* curr = slow;

        while(curr != nullptr){
            Node* next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        // Compare both halves

        Node* left = head;
        Node* right = prev;

        while(right != nullptr){
            if(left->data != right->data){
                cout<<"Not Palindrome.."<<endl;
                return false;
            }

            left = left->next;
            right = right->next;
        }

        cout<<"It is Palindrome.."<<endl;
        return true;
    }

    void print_list() {
        Node* temp = head;

        while(temp != nullptr) {
            cout << temp->data << "-->";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main() {
    List ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(2);
    ll.push_back(1);

    ll.print_list();

    ll.isPalindrome();

    return 0;
}