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
        vector<int> sfxSumVal;
        InorderTraversal(root, sfxSumVal);
        int sfxSum = 0;
        for (int i = sfxSumVal.size() - 1; i >= 0; --i) {
            sfxSum += sfxSumVal[i];
            sfxSumVal[i] = sfxSum;
        }
        newVal(root, sfxSumVal);
        return root;
    }

private:
    void InorderTraversal(TreeNode* root, vector<int>& sfxSumVal) {
        if (root == NULL)
            return;
        InorderTraversal(root->left, sfxSumVal);
        sfxSumVal.push_back(root->val);
        InorderTraversal(root->right, sfxSumVal);
    }
    int idx; //idx being a class member retains it's values over recursive calls
    void newVal(TreeNode* root, vector<int>& sfxSumVal) {
        if (root == NULL) {
            return;
        }
        newVal(root->left, sfxSumVal);
        root->val = sfxSumVal[idx];
        idx += 1;
        newVal(root->right, sfxSumVal);
    }
};