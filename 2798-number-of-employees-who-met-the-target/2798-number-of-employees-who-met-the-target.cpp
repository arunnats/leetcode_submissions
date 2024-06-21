class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) 
    {
        int ans = 0;

        for(const auto& hour: hours)
        {
            if(hour >= target)
                ans++;
        }

        return ans;
    }
};