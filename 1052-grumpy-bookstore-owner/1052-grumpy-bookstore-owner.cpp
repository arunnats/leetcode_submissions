class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) 
    {
        int n = customers.size();
        if (n == 0) return 0;
        
        vector<int> prefixGrumpy(n, 0);
        int ans = 0;
        int maxUnGrump = INT_MIN;
        int window = 0;
        int count = 0;

        for(int i = 0; i < n; i++)
        {
            if(grumpy[i] == 0)
            {
                ans = ans + customers[i];
            }
            if(count < minutes)
            {
                count++;
                if(grumpy[i] == 1)
                    window = window + customers[i];
            }  
            else 
            {
                if(grumpy[i] == 1)
                    window = window + customers[i];
                if(grumpy[i-minutes] == 1)
                    window = window - customers[i-minutes];
            }
            maxUnGrump = max(maxUnGrump, window);
        }

        return ans + maxUnGrump;
    }
};