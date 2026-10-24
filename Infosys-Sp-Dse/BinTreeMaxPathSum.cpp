// # Binary Tree Maximum Path Sum [Hard]

// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once.

// Note that the path does not need to pass through the root.

// The path sum of a path is the sum of the node's values in the path.

// Given the root of a binary tree, return the maximum path sum of any non-empty path.


// Code :- 

#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

// Initialize a Tree Structure
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution{
    public:

    int maxSum = INT_MIN;

    int maxGain(TreeNode* root){

        // Base case
        if(root == nullptr){
            return 0;
        }

        int leftGain = max(0, maxGain(root->left));
        int rightGain = max(0, maxGain(root->right));

        // Best path passing through this node
        int currentPathSum = root->val + leftGain + rightGain;

        maxSum = max(maxSum, currentPathSum);

        // Return only one branch to the parent
        return root->val + max(leftGain, rightGain);

    }

    int maxPathSum(TreeNode* root){
        maxGain(root);
        return maxSum;
    }
};

int main(){

    // Initialize the Tree with values
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;

    cout<<solution.maxPathSum(root)<<endl;

    return 0;
}