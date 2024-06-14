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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(!head)
            return 0;
            
        int count = 0;
        
        ListNode* current = head;

        while(current -> next != NULL)
        {
            count++;
            current = current -> next;
        }

        current -> next = head;

        int len = count + 1;
        count = count - k;
        while(count < 0)
        {
            count = count + len;
        }
        current = head;

        for(int i = 0; i < count; i ++)
        {
            current = current -> next;
        }
        head = current -> next;
        current -> next = NULL;

        return head;
    }
};