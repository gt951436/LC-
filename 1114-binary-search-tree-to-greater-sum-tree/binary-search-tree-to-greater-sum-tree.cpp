/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int pfxSum = 0;
        reverseInorder(root, pfxSum);
        return root;
    }
    void reverseInorder(TreeNode* root, int& pfxSum) {
        if (root == NULL)
            return;
        // reverese inorder traversal
        reverseInorder(root->right,pfxSum);
        pfxSum += (root->val); // add parent root value bcoz greater than and equal values..
        root->val = pfxSum;
        reverseInorder(root->left,pfxSum);
    }
};