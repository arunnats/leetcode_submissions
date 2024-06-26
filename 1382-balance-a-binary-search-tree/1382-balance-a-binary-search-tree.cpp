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
    TreeNode* balanceBST(TreeNode* root) 
    {
        vector<int> inOrder;

        util(root, inOrder);

        return buildTree(inOrder, 0, inOrder.size() -1 );
    }

    void util(TreeNode* root, vector<int>& inOrder)
    {
        if(root)
        {
            util(root->left, inOrder);
            inOrder.push_back(root->val);
            util(root->right, inOrder);
        }
    }

    TreeNode* buildTree(vector<int>& inOrder, int start, int end)
    {
        if(start > end)
            return nullptr;

        int mid = start + (end - start) / 2;

        TreeNode* newNode = new TreeNode(inOrder[mid]);
        newNode -> left = buildTree(inOrder, start, mid - 1);
        newNode -> right = buildTree(inOrder, mid + 1, end);

        return newNode;
    }
};