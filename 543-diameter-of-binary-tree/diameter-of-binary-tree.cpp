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
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        height(root, dia);
        return dia;
    }
    int height(TreeNode* root, int& dia) {
        if (root == NULL)
            return 0;

        int lHeight = height(root->left, dia);
        int rHeight = height(root->right, dia);
        dia = max(dia, lHeight + rHeight);
        return 1 + max(lHeight, rHeight);
    }
};