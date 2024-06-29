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
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> ans;

        if (root) 
        {
            string curr = to_string(root->val);
            util(root, ans, curr);
        }
        return ans;
    }

    void util(TreeNode* root, vector<string>& ans, string curr)
    {
        if (!root->left && !root->right) 
        {
            ans.push_back(curr);
            return;
        }

        if (root->left) 
        {
            util(root->left, ans, curr + "->" + to_string(root->left->val));
        }
        
        if (root->right) 
        {
            util(root->right, ans, curr + "->" + to_string(root->right->val));
        }
    }
};