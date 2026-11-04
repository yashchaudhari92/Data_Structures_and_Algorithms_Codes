// Given the head of a singly linked list, return the middle node of the linked list. If there are two middle nodes, 
// return the second middle node.


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

    Node* middleNode(){
        Node* slow = head;
        Node* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    void print_middle(){
        Node* mid = middleNode();

        if(mid != nullptr){
            cout << "Middle Node: " << mid->data << endl;
        }
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
    ll.push_back(4);
    ll.push_back(5);

    ll.print_list();

    ll.print_middle();

    return 0;
}