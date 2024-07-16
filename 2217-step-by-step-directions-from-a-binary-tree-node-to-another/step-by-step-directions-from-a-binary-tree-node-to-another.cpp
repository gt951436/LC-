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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lowestCommonAncestor =
            findLowestCommonAncestor(root, startValue, destValue);

        string pathToStart;
        string pathToDest;

        findPath(lowestCommonAncestor, startValue, pathToStart);
        findPath(lowestCommonAncestor, destValue, pathToDest);

        string directions;
        directions.append(pathToStart.length(), 'U');
        directions.append(pathToDest);

        return directions;
    }

private:
    TreeNode* findLowestCommonAncestor(TreeNode* node, int value1, int value2) {
        if (node == nullptr) return nullptr;

        if (node->val == value1 || node->val == value2) return node;

        TreeNode* leftLCA =
            findLowestCommonAncestor(node->left, value1, value2);
        TreeNode* rightLCA =
            findLowestCommonAncestor(node->right, value1, value2);

        if (leftLCA == nullptr)
            return rightLCA;
        else if (rightLCA == nullptr)
            return leftLCA;
        else
            return node;
    }
    bool findPath(TreeNode* node, int targetValue, string& path) {
        if (node == nullptr) return false;
        if (node->val == targetValue) return true;
        path.push_back('L');
        if (findPath(node->left, targetValue, path)) {
            return true;
        }
        path.pop_back();
        path.push_back('R');
        if (findPath(node->right, targetValue, path)) {
            return true;
        }
        path.pop_back();

        return false;
    }
};