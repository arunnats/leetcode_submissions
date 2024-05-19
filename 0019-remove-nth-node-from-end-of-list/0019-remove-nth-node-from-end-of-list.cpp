class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || !head->next) 
        {
            delete head;  
            return nullptr; 
        }

        ListNode* current = head;
        int size = 0;

        while (current != NULL) 
        {
            size++;
            current = current->next;
        }

        size = size - n;

        if (size == 0) 
        {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        current = head;
        ListNode* prev = NULL;

        for (int i = 0; i < size; i++) 
        {
            prev = current;
            current = current->next;
        }

        prev->next = current->next;
        delete current; 

        return head;
    }
};
