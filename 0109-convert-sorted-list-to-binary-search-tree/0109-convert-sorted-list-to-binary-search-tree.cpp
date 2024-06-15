/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) 
    {
        if(!head)
            return NULL;

        // vector<int> nums;

        // while(head)
        // {
        //     nums.push_back(head->val);
        //     head = head -> next;
        // }
        // int n = nums.size();

        // return util(nums, 0, n-1);

        if (!head) return nullptr;
        return util(head, nullptr);
    }

    TreeNode* util(ListNode* head, ListNode* tail)
    {
        if (head == tail) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != tail && fast->next != tail) 
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode* Node = new TreeNode(slow->val);

        Node->left = util(head, slow);
        Node->right = util(slow->next, tail);

        return Node;
    }

    // TreeNode* util(vector<int>& nums, int startIndex, int endIndex) 
    // {
    //     if( startIndex > endIndex )
    //         return NULL;

    //     int mid = startIndex + (endIndex - startIndex) / 2;

    //     TreeNode* Node = new TreeNode(nums[mid]);

    //     Node -> left = util(nums, startIndex, mid-1);
    //     Node -> right = util(nums, mid+1, endIndex);

    //     return Node;
    // }
};