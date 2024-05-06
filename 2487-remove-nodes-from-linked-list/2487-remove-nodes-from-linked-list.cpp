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
class Solution {
public:
    ListNode* removeNodes(ListNode* head) 
    {
        int max = recursion(head->next, head, INT_MIN );

        if(max > head->val)
        {
            head = head->next;
        }

        return head;
    }

    int recursion(ListNode* current, ListNode* prev,int max)
    {
        
        if(current->next == NULL)
        {
            max = current->val;
            return max;
        }

        max = recursion(current->next, current, max);

        if(max > current->val)
        {
            prev->next = current->next;
            return max;
        }
        else if(max <= current->val)
        {
            max = current->val;
            return max;
        }
        return max;
    }
};