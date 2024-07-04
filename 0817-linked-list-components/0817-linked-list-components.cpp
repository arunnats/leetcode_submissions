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
    int numComponents(ListNode* head, vector<int>& nums) 
    {
        unordered_set<int> present;

        for(const auto& num: nums)
        {
            present.insert(num);
        }    
        int ans = 0;
        int comp = -1;

        ListNode* curr = head;

        while(curr)
        {
            if(present.find(curr->val) != present.end())
            {
                if(comp == -1)
                    ans++;
                comp = 1;
            }
            else
            {
                comp = -1;
            }
            curr = curr->next;
        }

        return ans;
    }
};