// Find and remove nth node from end of linked list. from end means, from last counting is start from 1.

// Note :- 
// We always use forward tracking because, backward tracking is not possible in linked list. Therefore we need to find front of the nth node, here 
// is the formula for this. -> size-n+1

// for ex, suppose n=2 from last, size = 5, then (size - n + 1) -> 5 - 2 + 1 = 4 from front. we have to delete the 4th node from start.


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

    void remove(int n){
        int sz = size();

        // Invalid position
        if(n <= 0 || n > sz) {
            cout << "Invalid position" << endl;
            return;
        }

        // Case 1: Delete head node
        if(n == sz) {
            Node* toDelete = head;

            head = head->next;

            if(head == nullptr) {
                tail = nullptr;
            }

            delete toDelete;
            return;
        }

        // Case 2: Delete any other node
        Node* prev = head;

        for(int i = 1; i < sz-n; i++) {
            prev = prev->next;
        }

        Node* toDelete = prev->next;

        cout << "Going to delete: " << toDelete->data << endl;

        prev->next = toDelete->next;

        // Update tail if deleting last node
        if(toDelete == tail) {
            tail = prev;
        }

        delete toDelete;
    }

    int size(){
        int sz = 0;
        Node* temp = head;

        while(temp != nullptr){
            temp = temp->next;
            sz++;
        }

        return sz;
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

    ll.remove(2);

    ll.print_list();

    return 0;
}