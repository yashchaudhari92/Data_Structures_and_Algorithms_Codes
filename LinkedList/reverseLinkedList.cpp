// Given the head of a singly linked list, reverse the list, and return the reversed list.

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

    void reverse(){
        Node* curr = head;
        Node* prev = nullptr;

        while(curr != nullptr){
            Node* next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        head = prev;
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
    ll.push_back(3);

    ll.print_list();

    ll.reverse();

    ll.print_list();

    return 0;
}