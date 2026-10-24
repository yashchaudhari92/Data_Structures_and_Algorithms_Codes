// # 337. House Robber III — Medium

// The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

// Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree.

// It will automatically contact the police if two directly-linked houses were broken into on the same night.

// Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.


// Code :- using Tree DP + DFS + Recursion.

// Here we also have two choices :-
// Rob this node: We cannot rob its children, so we add the best answers from its grandchildren.

// Skip this node: We can choose independently whether to rob or skip each child.


#include<iostream>
#include<algorithm>
#include<utility>
#include<climits>
using namespace std;


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

    pair<int, int> solve(TreeNode* root){

        if(root == nullptr){
            return {0, 0};
        }

        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);

        // If we rob this node, we must skip both children
        int robThis = root->val + left.second + right.second;

        // If we skip this node, each child can be robbed or skipped
        int skipThis = max(left.first, left.second) + max(right.first, right.second);

        return {robThis, skipThis};

    }

    int rob(TreeNode* root){
      pair<int, int> result = solve(root);
      return max(result.first, result.second);
    }

};

int main(){

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);

    Solution solution;

    cout<<solution.rob(root)<<endl;

    return 0;
}
