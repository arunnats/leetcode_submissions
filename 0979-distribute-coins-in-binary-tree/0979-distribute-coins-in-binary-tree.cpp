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
    int distributeCoins(TreeNode* root, TreeNode* parent = NULL) 
    {
        if(root == NULL)
            return 0;

        int moves = distributeCoins(root -> left, root) + distributeCoins(root -> right, root);

        int cuurentCoins = root -> val - 1;
        if(parent != NULL)
            parent -> val = parent -> val + cuurentCoins;

        moves = moves + abs(cuurentCoins);

        return moves;
    }
};