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

bool isIdentical(Node* root1, Node* root2){

    // Base Case
    if(root1 == NULL && root2 == NULL){                // Both NULL return true
        return true;
    } else if(root1 == NULL || root2 == NULL){         // Any one who is individually NULL return false
        return false;
    }

    if(root1->data != root2->data){
        return false;
    }

    // First always make a left tree call then make a right tree call.

    return isIdentical(root1->left, root2->left)
            && isIdentical(root1->right, root2->right);
}

bool isSubtree(Node* root, Node* subRoot){

    // Base Case
    if(root == NULL && subRoot == NULL){                // Both NULL return true
        return true;
    } else if(root == NULL || subRoot == NULL){         // Any one who is individually NULL return false
        return false;
    }

    if(root->data == subRoot->data){
        if(isIdentical(root, subRoot)){                 // Return true only when isIdentical return true, otherwise do nothing.
            return true; 
        }
    }

    int isLeftSubtree = isSubtree(root->left, subRoot);
    if(!isLeftSubtree){
        return isSubtree(root->right, subRoot);
    }

    return true;
}

int main(){
    vector<int> nodes = { 1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);

    Node* subRoot = new Node(2);
    subRoot->left = new Node(4);
    subRoot->right = new Node(5);

    cout<< isSubtree(root, subRoot) <<endl;
    return 0;
}
