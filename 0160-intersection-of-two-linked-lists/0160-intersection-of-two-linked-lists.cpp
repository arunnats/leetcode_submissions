/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        if(!headA || !headB)
            return NULL;

        int lenA = 0;
        int lenB = 0;
        ListNode *tempA = headA;
        ListNode *tempB = headB;

        while(headA -> next != NULL)
        {   
            lenA++;
            headA = headA -> next;
        }

        while(headB -> next != NULL)
        {   
            lenB++;
            headB = headB -> next;
        }

        if(lenA > lenB)
            return check(tempA, tempB, lenA-lenB);
        else
            return check(tempB, tempA, lenB-lenA);

        return NULL;
    }

    ListNode *check(ListNode * longList, ListNode * shortList, int diff)
    {
        while (longList && diff--) 
        {
            longList = longList->next;
        }

        while (longList && shortList) 
        {
            if (longList == shortList) 
            {
                return longList;
            }
            longList = longList->next;
            shortList = shortList->next;
        }

        return NULL;
    }
};