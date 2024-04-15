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
    int sum = 0;
    int sumNumbers(TreeNode* root) {

        InorderDigitsToNum(root, 0);
        return sum;
    }

    void InorderDigitsToNum(TreeNode* root, int num) {

        if (root == NULL)
            return;
        num = root->val + 10 * num;
        if (root->left == NULL && root->right == NULL) { // leaf node reached
            sum += num;
        }
        InorderDigitsToNum(root->left, num);
        InorderDigitsToNum(root->right, num);
    }
};