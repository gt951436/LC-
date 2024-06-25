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
        vector<int> pfxSumVal;
        InorderTraversal(root, pfxSumVal);
        int pfxSum = 0;
        for (int i = pfxSumVal.size() - 1; i >= 0; --i) {
            pfxSum += pfxSumVal[i];
            pfxSumVal[i] = pfxSum;
        }
        newVal(root, pfxSumVal);
        return root;
    }

private:
    void InorderTraversal(TreeNode* root, vector<int>& pfxSumVal) {
        if (root == NULL)
            return;
        InorderTraversal(root->left, pfxSumVal);
        pfxSumVal.push_back(root->val);
        InorderTraversal(root->right, pfxSumVal);
    }
    int idx;
    void newVal(TreeNode* root, vector<int>& pfxSumVal) {
        if (root == NULL) {
            return;
        }
        newVal(root->left, pfxSumVal);
        root->val = pfxSumVal[idx];
        idx += 1;
        newVal(root->right, pfxSumVal);
    }
};