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
    vector<TreeNode*> allPossibleFBT(int n) 
    {
        unordered_map<int, vector<TreeNode*>> memo;

        memo[1] = {new TreeNode(0)};

        for(int i = 2; i <=n; i++)
        {
            memo[i] = dfs(i, memo);
        }

        return memo[n];
    }

    vector<TreeNode*> dfs(int n, unordered_map<int, vector<TreeNode*>>& memo)
    {
        if (memo.count(n)) 
        {
            return memo[n];
        }

        vector<TreeNode*> result;

        for (int leftNodes = 1; leftNodes < n; leftNodes += 2) 
        {
            int rightNodes = n - 1 - leftNodes;

            vector<TreeNode*> leftTrees = dfs(leftNodes, memo);
            vector<TreeNode*> rightTrees = dfs(rightNodes, memo);

            for (TreeNode* left : leftTrees) 
            {
                for (TreeNode* right : rightTrees)
                {
                    TreeNode* root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }   

        memo[n] = result; 
        return result;
    }
};