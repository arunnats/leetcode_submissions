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
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, int> diffMap;

        diffMap[root->val]++;

        return util(root->left, k, diffMap) || util(root->right, k, diffMap);
    }

    bool util(TreeNode* root, int k, unordered_map<int, int>& diffMap) {
        if(!root)
            return false;

        if(diffMap.find(k - root->val) != diffMap.end())
            return true;
        diffMap[root->val]++;


        return util(root->left, k, diffMap) || util(root->right, k, diffMap);
    }
};