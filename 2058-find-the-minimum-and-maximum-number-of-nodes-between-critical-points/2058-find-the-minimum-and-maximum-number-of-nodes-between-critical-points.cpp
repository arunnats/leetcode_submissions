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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) 
    {
        vector<int> ans;
        vector<int> criticalPoints;

        if (!head || !head->next || !head->next->next) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = head->next->next;
        int index = 1;
        
        while(next)
        {
            if ((curr->val > prev->val && curr->val > next->val) || (curr->val < prev->val && curr->val < next->val)) 
            {
                criticalPoints.push_back(index);
            }
            prev = curr;
            curr = next;
            next = next->next;
            index++;
        }

        int n = criticalPoints.size();
        if (n < 2) 
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }

        int minInterval = INT_MAX;

        for(int i = 1; i < n; i++)
        {
            minInterval = min(minInterval, criticalPoints[i] - criticalPoints[i - 1]);
        }

        int maxInterval = criticalPoints[n-1] - criticalPoints[0];

        ans.push_back(minInterval);
        ans.push_back(maxInterval);

        return ans;
    }
};