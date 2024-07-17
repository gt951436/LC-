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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> st;
        for (int& it : to_delete) {
            st.insert(it);
        }
        deleteNodeHelper(root, st, ans); // pass ans by reference nahi to har recursive call pe naya vector banega!

        if (st.find(root->val) == st.end()) { // root ko delete karna h ya nhai?
            ans.push_back(root);
        }
        return ans;
    }
    TreeNode* deleteNodeHelper(TreeNode* root, unordered_set<int>& st,
                               vector<TreeNode*>& ans) {
        if (root == NULL)
            return NULL;
        root->left = deleteNodeHelper(root->left, st, ans);
        root->right = deleteNodeHelper(root->right, st, ans);

        if (st.find(root->val) != st.end()) {
            if (root->left != NULL)
                ans.push_back(root->left);

            if (root->right != NULL)
                ans.push_back(root->right);

            return NULL; // delete hogya node!
        }
        return root;
    }
};