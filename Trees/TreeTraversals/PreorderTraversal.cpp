// Preorder Traversal

// Rules:- 
// 1. root
// 2. left subtree
// 3. right subtree

// Linear Time Complexity -> O(n)



#include<iostream>
#include<vector>

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

void preOrder(Node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    vector<int> nodes = { 1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);

    preOrder(root);
    cout<<endl;

    return 0;
}
