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
class Solution 
{
    int preIndex = 0; 
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        int n = preorder.size();
        if(n == 0)
            return NULL;

        unordered_map <int, int> inIndexmap;

        for (int i = 0; i < n; i++)
        {
            inIndexmap[inorder[i]] = i;
        }

        return buildTreeUtil(preorder, 0, n-1, inIndexmap);
    }

    TreeNode* buildTreeUtil(vector<int>& preorder, int inStrt, int inEnd, unordered_map <int, int>& inIndexmap) 
    {

        if (inStrt > inEnd) 
            return NULL; 

        int currentVal = preorder[preIndex++];
        TreeNode* tNode = new TreeNode(currentVal); 

        if (inStrt == inEnd) 
            return tNode; 

        int inIndex = inIndexmap[currentVal]; 
    
        tNode -> left = buildTreeUtil(preorder, inStrt, inIndex - 1, inIndexmap);
        tNode -> right = buildTreeUtil(preorder, inIndex + 1, inEnd, inIndexmap);

        return tNode;  
    }
};