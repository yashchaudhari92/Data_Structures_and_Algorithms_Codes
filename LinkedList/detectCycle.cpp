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

    bool isCycle(Node* head) {
        Node* slow = head;
        Node* fast = head;

        while(fast != nullptr && fast->next != nullptr) {

            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                return true;
            }
        }

        return false;
    }

    void createCycle() {
        if(head != nullptr) {
            tail->next = head;
        }
    }

    bool checkCycle() {
        return isCycle(head);
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

    ll.createCycle();

    if(ll.checkCycle()) {
        cout << "Cycle Detected" << endl;
    }
    else {
        cout << "Cycle not detected" << endl;
    }

    return 0;
}