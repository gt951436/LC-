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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorderTraversal(root, arr);
        int n = arr.size();
        return arrayToBST(arr, 0, n - 1);
    }
    void inorderTraversal(TreeNode* root, vector<int>& arr) {
        if (root == NULL)
            return;
        inorderTraversal(root->left, arr);
        arr.push_back(root->val);
        inorderTraversal(root->right, arr);
    }
    // void preorderTraversal(TreeNode* node) {
    //     if (node == NULL)
    //         return;
    //     cout << node->val << " ";
    //     preorderTraversal(node->left);
    //     preorderTraversal(node->right);
    // }
    TreeNode* arrayToBST(vector<int> arr, int s, int e) {
        if (s > e)
            return NULL;

        int mid = s + (e - s) / 2;
        // TreeNode* newRoot;
        // newRoot->val = arr[mid];
        TreeNode *newLeft = arrayToBST(arr, s, mid - 1);
        TreeNode *newRight = arrayToBST(arr, mid + 1, e);
        return new TreeNode(arr[mid],newLeft,newRight);
    }
};