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
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {   
        int n = nums.size();

        return util(nums, 0, n-1);
    }

    TreeNode* util(vector<int>& nums, int startIndex, int endIndex) 
    {
        if( startIndex > endIndex )
            return NULL;

        int mid = startIndex + (endIndex - startIndex) / 2;

        TreeNode* Node = new TreeNode(nums[mid]);

        Node -> left = util(nums, startIndex, mid-1);
        Node -> right = util(nums, mid+1, endIndex);

        return Node;
    }
};