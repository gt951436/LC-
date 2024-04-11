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
    int levelOrderTraversal2(TreeNode  * root){
        if(root == NULL){
            return 0;
        }
        queue<TreeNode *>q;
        q.push(root);
        q.push(NULL);
        int depth = 0;
        while(q.size() > 1){
            TreeNode * temp = q.front();
            q.pop();
            if(temp == NULL){
                q.push(NULL);
                depth++;
            }
            else{
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }

            }

        }
        return depth + 1;
    }
    int maxDepth(TreeNode* root) {
        return levelOrderTraversal2(root);
        
    }
};