/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) 
    {
        vector<int> ans;

        recurse(root, ans);

        return ans;   
    }

    void recurse(Node* root, vector<int> &ans)
    {
        if(root == NULL)
            return;

        ans.push_back(root->val);

        for(const auto& child : root->children) 
        {
            recurse(child, ans);
        } 
    }
};