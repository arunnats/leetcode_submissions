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
    int maxPathSum(TreeNode* root) 
    {
        int ans = INT_MIN;

        util(root, ans);

        return ans;
    }

    int util(TreeNode* root, int& ans)
    {
        if(!root)
            return 0;

        int l = util(root->left, ans);
        int r =  util(root->right, ans);

        l = max(l, 0);
        r = max(r, 0);

        ans = max(ans, root->val + l + r);

        return root->val + max(l, r);
    }
};