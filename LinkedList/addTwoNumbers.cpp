// Add Two Numbers
// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, 
// and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.


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

// Add two numbers
Node* addTwoNumbers(Node* l1, Node* l2) {

    // Dummy node for result
    Node* dummy = new Node(0);
    Node* curr = dummy;

    int carry = 0;

    // Traverse both linked lists
    while (l1 != nullptr || l2 != nullptr || carry != 0) {

        int sum = carry;

        // Add first list digit
        if (l1 != nullptr) {
            sum += l1->data;
            l1 = l1->next;
        }

        // Add second list digit
        if (l2 != nullptr) {
            sum += l2->data;
            l2 = l2->next;
        }

        // Calculate digit and carry
        int digit = sum % 10;
        carry = sum / 10;

        // Create new result node
        curr->next = new Node(digit);
        curr = curr->next;
    }

    Node* result = dummy->next;

    delete dummy;

    return result;
}

// Main function
int main() {

    List l1, l2, result;

    int n, m, val;

    // First linked list
    cout << "Enter number of nodes in first list: ";
    cin >> n;

    cout << "Enter digits of first list in reverse order: ";

    for (int i = 0; i < n; i++) {
        cin >> val;
        l1.push_back(val);
    }

    // Second linked list
    cout << "Enter number of nodes in second list: ";
    cin >> m;

    cout << "Enter digits of second list in reverse order: ";

    for (int i = 0; i < m; i++) {
        cin >> val;
        l2.push_back(val);
    }

    cout << "\nFirst Number: ";
    l1.print_list();

    cout << "Second Number: ";
    l2.print_list();

    // Addition
    result.head = addTwoNumbers(l1.head, l2.head);

    cout << "Result: ";
    result.print_list();

    return 0;
}
