

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

    bool traverse(TreeNode* p, TreeNode* q){
        if(p==NULL || q==NULL) return p==q;

        if(p->val != q-> val) return false;

        return traverse(p->left,q->left) && traverse(p->right,q->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Brute force might be writing the entire inorder or any traversal of both trees
        // And compare the stored vectors
        // Time Complexity : O(N) 
        // Space Complexity : O(max(PHeight,QHeight)) recursion + O(N+M) array

        // Simultaneous traversal
        // Time Complexity : O(N)
        // Space Complexity : O(max(PHeight,QHeight)) 
        // return traverse(p,q);
    }
};
