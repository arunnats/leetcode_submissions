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
class Solution
{
public:
    ListNode *doubleIt(ListNode *head)
    {
        if (recursive(head))
        {
            ListNode *newHead = new ListNode(1);
            newHead->next = head;
            head = newHead;
            return head;
        }
        return head;
    }

    int recursive(ListNode *head)
    {
        if (head == NULL)
            return 0;

        int carry = recursive(head->next);

        int temp = (head->val * 2) + carry;
        head->val = temp % 10;
        temp = temp / 10;
        return temp;
    }
};