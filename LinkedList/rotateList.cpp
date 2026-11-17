// Given the head of a linked list, rotate the list to the right by k places.
// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]

// Code :- 


#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Linked List class
class List {
public:
    Node* head;
    Node* tail;

    List() {
        head = nullptr;
        tail = nullptr;
    }

    // Insert node at the end
    void push_back(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Display linked list
    void print_list() {
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->data;

            if (temp->next != nullptr) {
                cout << " -> ";
            }

            temp = temp->next;
        }

        cout << endl;
    }
};

// Rotate linked list to the right
Node* rotateRight(Node* head, int k) {

    // Step 1: Handle empty list or single node
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Step 2: Find length and tail
    int len = 1;
    Node* tail = head;

    while (tail->next != nullptr) {
        tail = tail->next;
        len++;
    }

    // Step 3: Remove unnecessary rotations
    k = k % len;

    if (k == 0) {
        return head;
    }

    // Step 4: Make circular linked list
    tail->next = head;

    // Step 5: Find new tail
    int stepsToNewTail = len - k;
    Node* newTail = head;

    for (int i = 1; i < stepsToNewTail; i++) {
        newTail = newTail->next;
    }

    // Step 6: Find new head
    Node* newHead = newTail->next;

    // Step 7: Break circular connection
    newTail->next = nullptr;

    return newHead;
}

// Main function
int main() {

    List ll;

    int n, val, k;

    // Input number of nodes
    cout << "Enter number of nodes: ";
    cin >> n;

    // Create linked list
    cout << "Enter linked list elements: ";

    for (int i = 0; i < n; i++) {
        cin >> val;
        ll.push_back(val);
    }

    // Input rotation count
    cout << "Enter k: ";
    cin >> k;

    cout << "\nOriginal Linked List: ";
    ll.print_list();

    // Rotate linked list
    ll.head = rotateRight(ll.head, k);

    cout << "Rotated Linked List: ";
    ll.print_list();

    return 0;
}
