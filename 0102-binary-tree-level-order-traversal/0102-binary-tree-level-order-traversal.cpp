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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            vector<int> temp;
            for(int itr=0; itr<n; itr++) {
                TreeNode *currRoot = q.front();
                q.pop();
                if(currRoot->left != NULL) {
                    q.push(currRoot->left);
                }
                if(currRoot->right != NULL){
                    q.push(currRoot->right);
                }
                temp.push_back(currRoot->val);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};