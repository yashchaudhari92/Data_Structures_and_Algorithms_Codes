// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
// Return the head of the merged linked list.


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

    // Merge two sorted lists
    void merge(List& list1, List& list2){
        Node* i = list1.head;
        Node* j = list2.head;

        Node dummy(-1);
        Node* temp = &dummy;

        while(i != nullptr && j != nullptr){
            if(i->data <= j->data){
                temp->next = i;
                i = i->next;
            } else {
                temp->next = j;
                j = j->next;
            }

            temp = temp->next;
        }

        // Attach remaining nodes
        if(i != nullptr){
            temp->next = i;
        }

        if(j != nullptr){
            temp->next = j;
        }

        // Update head and tail
        head = dummy.next;

        if(head == nullptr){
            tail = nullptr;
        } else if(i != nullptr){
            tail = list1.tail;
        } else if(j != nullptr){
            tail = list2.tail;
        } else {
            temp = tail;
        }

        // Transfer ownership of the nodes
        list1.head = list1.tail = nullptr;
        list2.head = list2.tail = nullptr;
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
    List ll1;
    List ll2;
    List merged;

    ll1.push_back(1);
    ll1.push_back(2);
    ll1.push_back(4);

    ll2.push_back(1);
    ll2.push_back(3);
    ll2.push_back(4);

    cout << "List 1: ";
    ll1.print_list();

    cout << "List 2: ";
    ll2.print_list();

    merged.merge(ll1, ll2);

    cout << "Merged List: ";
    merged.print_list();

    return 0;
}