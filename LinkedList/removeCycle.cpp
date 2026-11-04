// Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following 
// the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). 
// It is -1 if there is no cycle. Note that pos is not passed as a parameter.

// Do not modify the linked list.


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

    int getData() {
        return data;
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

    // Create a cycle for testing
    // pos = 0 means cycle connects to first node
    // pos = 2 means cycle connects to third node
    void createCycle(int pos) {
        if(head == nullptr || pos < 0) return;

        Node* temp = head;

        for(int i = 0; i < pos && temp != nullptr; i++) {
            temp = temp->next;
        }

        if(temp != nullptr) {
            tail->next = temp;
        }
    }

    // Detect and remove cycle
    Node* removeCycle() {

        Node* slow = head;
        Node* fast = head;

        bool isCycle = false;

        // Step 1: Detect cycle
        while(fast != nullptr && fast->next != nullptr) {

            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                isCycle = true;
                break;
            }
        }

        // Step 2: No cycle
        if(!isCycle) {
            return nullptr;
        }

        // Step 3: Reset slow to head
        slow = head;

        // Case 1: Cycle starts at head
        if(slow == fast) {

            while(fast->next != slow) {
                fast = fast->next;
            }

            fast->next = nullptr;
        }

        // Case 2: Cycle starts in middle
        else {

            Node* prev = fast;

            while(slow != fast) {

                slow = slow->next;

                prev = fast;

                fast = fast->next;
            }

            prev->next = nullptr;
        }

        return slow;
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

    // Create cycle: node 5 connects to node 3
    ll.createCycle(2);

    Node* cycleStart = ll.removeCycle();

    if(cycleStart != nullptr) {
        cout << "Cycle detected and removed!" << endl;
        cout << "Cycle started at: " << cycleStart->getData() << endl;
    }
    else {
        cout << "No cycle detected!" << endl;
    }

    cout << "Linked List after removing cycle:" << endl;
    ll.print_list();

    return 0;
}
