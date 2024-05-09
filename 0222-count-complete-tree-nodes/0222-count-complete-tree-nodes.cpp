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
    int countNodes(TreeNode* root) 
    {   
        return countNodesRecursive(root);
    }

    int countNodesRecursive(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }

        int count = 1;
        count = count + countNodesRecursive(root -> left);
        count = count + countNodesRecursive(root -> right);

        return count;
    }
};