/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) { return root; }

        TreeNode* leftSubtree = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightSubtree = lowestCommonAncestor(root->right, p, q);

        if(leftSubtree != NULL && rightSubtree != NULL) {
            return root;
        }

        if(leftSubtree != NULL) {
            return leftSubtree;
        }

        return rightSubtree;
    }
};