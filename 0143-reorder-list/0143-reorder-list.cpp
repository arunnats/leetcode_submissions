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
    void reorderList(ListNode* head) 
    {
        if (!head || !head->next) return;
        
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = NULL;

        while (fast != NULL && fast->next != NULL) 
        {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
        }
        prev->next = NULL;
        
        ListNode* head2 = reverseList(slow, NULL);
        // printList(head2);

        while(head != NULL && head2 != NULL)
        {
            ListNode* temp1 = head->next;
            ListNode* temp2 = head2->next;

            head->next = head2;  
            if (temp1 == NULL) break;

            head2->next = temp1; 

            head = temp1;  
            head2 = temp2;
        }
    }

    ListNode* reverseList(ListNode* curr, ListNode* prev)
    {
        if(curr == NULL)
            return prev;  
        ListNode* nextNode = curr->next;  
        curr->next = prev;
        return reverseList(nextNode, curr);
    }

    // void printList(ListNode* curr)
    // {
    //     while (curr != NULL) 
    //     {
    //     cout << curr->val << "\n";
    //     curr = curr->next;
    //     }
    // }
};