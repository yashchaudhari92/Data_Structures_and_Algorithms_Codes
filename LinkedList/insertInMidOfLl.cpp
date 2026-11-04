// Insert in middle of linked list
// Insert node at given position in linked list.

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

    void insert(int val, int pos){
        Node* newNode = new Node(val);
        Node* temp = head;

        for(int i=0; i<pos-1; i++){
            if(temp == nullptr){
                cout<<"Position is invalid"<<endl;
                return;
            }

            temp = temp->next;      // pos - 1 -> Prev of pos.
        }

        newNode->next = temp->next;
        temp->next = newNode;

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

    ll.insert(4, 2);

    ll.print_list();

    return 0;
}