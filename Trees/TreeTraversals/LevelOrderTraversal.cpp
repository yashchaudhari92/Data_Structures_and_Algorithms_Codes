// Level Order Traversal ( Solved Using Queue Data Structure)

// Rules:- Traverse and prints elements level by level

// 1. create a queue and push the root node into it.
// 2. Run the loop until the queue gets empty.

// Linear Time Complexity -> O(n)



#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

static int idx = -1;

Node* buildTree(vector<int> nodes){
    idx++;

    if(nodes[idx] == -1){
        return NULL;
    }

    Node* CurrNode = new Node(nodes[idx]);
    CurrNode->left = buildTree(nodes);
    CurrNode->right = buildTree(nodes);

    return CurrNode;
}

void levelOrder(Node* root){

    if(root == NULL){
        return;
    }

    // 1. create a queue and push the root node into it.
    queue<Node*> q;
    q.push(root);

    // 2. Run the loop until the queue gets empty.
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        cout<< curr->data << " ";

        if(curr->left != NULL){
            q.push(curr->left);
        }

        if(curr->right != NULL){
            q.push(curr->right);
        }
    }

    cout<<endl;
}

int main(){
    vector<int> nodes = { 1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);

    levelOrder(root);
    cout<<endl;

    return 0;
}



// Variation in printing nodes

//      1
//     2 3
//    4 5 6

// void levelOrder(Node* root){

//     if(root == NULL){
//         return;
//     }

//     queue<Node*> q;
//     q.push(root);
//     q.push(NULL);

//     while(!q.empty()){
//         Node* curr = q.front();
//         q.pop();

//         if(curr == NULL){
//             cout<<endl;
//             if(q.empty()){
//                 break;
//             }

//             q.push(NULL);  // To track Next Line
//         }

//         cout<< curr->data << " ";

//         if(curr->left != NULL){
//             q.push(curr->left);
//         }

//         if(curr->right != NULL){
//             q.push(curr->right);
//         }
//     }

//     cout<<endl;
// }