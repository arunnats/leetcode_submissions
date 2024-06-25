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
    TreeNode* bstToGst(TreeNode* root) 
    {
        util(root, 0);
        return root;
    }

    int util(TreeNode* root, int sum)
    {
        if(!root)
            return sum;

        sum = util(root->right, sum);
        root->val += sum;
        sum = root->val;
        sum = util(root->left, sum);

        return sum;
    }
};