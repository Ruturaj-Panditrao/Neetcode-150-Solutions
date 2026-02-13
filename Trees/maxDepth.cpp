// Leetcode 104. Maximum Depth of Binary Tree : https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    // Time Complexity : O(N)
    // Time Complexity is O(N) and not O(height)
    // Because we will visit each and every node
    // Space Complexity : O(height)

    int height(TreeNode* node){
        if(node==NULL) return 0;
        int lh = 0;
        int rh = 0;

        lh = height(node->left);

        rh = height(node->right);

        return 1 + max(lh,rh);
    }

    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int lh = height(root->left);
        int rh = height(root->right);

        return 1 + max(lh,rh);
    }
};
