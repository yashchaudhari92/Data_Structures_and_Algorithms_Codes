// Approach -> O(n^2)

// What is mean by Diameter?
// -> Diameter means, The number of nodes in the longest path between any two nodes.

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

int height(Node* root){

    if(root == NULL){
        return 0;
    }

    int leftHt = height(root->left);
    int rightHt = height(root->right);

    int currHt = max(leftHt, rightHt) + 1;

    return currHt;
}

// O(n^2) Approach

// int diam1(Node* root){

//     if(root == NULL){
//         return 0;
//     }

//     int currDiam = height(root->left) + height(root->right) + 1;    // Assume that diameter Always pass through root.
//     int leftDiam = diam1(root->left);                               // left subtree diameter
//     int rightDiam = diam1(root->right);                             // right subtree diameter

//     return max(currDiam, max(leftDiam, rightDiam));                 // return the max of all the 3, & it will be the diameter of tree.
// }


// O(n) Approach
pair<int,int> diam2(Node* root){

    // Base Case
    if(root == NULL){
        return make_pair(0, 0);
    }

    pair<int, int> leftInfo = diam2(root->left);        // LD, LH
    pair<int, int> rightInfo = diam2(root->right);      // RD, RH

    int currDiam = leftInfo.second + rightInfo.second + 1;
    int finalDiam = max(currDiam, max(leftInfo.first, rightInfo.first));
    int finalHt = max(leftInfo.second, rightInfo.second) + 1;

    return make_pair(finalDiam, finalHt);
}

int main(){
    vector<int> nodes = { 1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root = buildTree(nodes);

    // cout<<"Diameter = "<<diam1(root)<<endl;
    cout<<"Diameter = "<<diam2(root).first<<endl;
    return 0;
}
