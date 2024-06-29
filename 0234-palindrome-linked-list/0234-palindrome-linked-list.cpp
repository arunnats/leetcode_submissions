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
    bool isPalindrome(ListNode* head) 
    {
        stack<int> stack;
        ListNode* current = head;

        while (current) 
        {
            stack.push(current->val);
            current = current->next;
        }

        current = head;
        while (current) 
        {
            int temp = stack.top();
            stack.pop();

            if(current->val != temp)
                return false;

            current = current->next;
        }

        return true;
    }
};