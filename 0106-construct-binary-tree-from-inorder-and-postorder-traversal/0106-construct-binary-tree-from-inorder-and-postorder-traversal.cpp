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
    int postIndex;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        if (n == 0)
            return nullptr;
        
        postIndex = n - 1;

        unordered_map<int, int> inIndexMap;
        for (int i = 0; i < n; i++) {
            inIndexMap[inorder[i]] = i;
        }

        return buildTreeUtil(postorder, inIndexMap, 0, n - 1);
    }

    TreeNode* buildTreeUtil(vector<int>& postorder, unordered_map<int, int>& inIndexMap, int inStart, int inEnd) {
        if (inStart > inEnd)
            return nullptr;

        int currentVal = postorder[postIndex--];
        TreeNode* TNode = new TreeNode(currentVal);

        if (inStart == inEnd)
            return TNode;

        int inIndex = inIndexMap[currentVal];

        TNode->right = buildTreeUtil(postorder, inIndexMap, inIndex + 1, inEnd);
        TNode->left = buildTreeUtil(postorder, inIndexMap, inStart, inIndex - 1);

        return TNode;
    }
};