class Solution 
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        if (intervals.empty()) return {};
        vector<vector<int>> ans; 

        sort(intervals.begin(), intervals.end(), compareFirstElement);

        int current = 0;

        for(const auto& pair: intervals)
        {
            if (current == 0)
            {
                ans.push_back(pair);
                current++;
            }
            else if(pair[0] > ans[current - 1][0] && pair[0] > ans[current - 1][1])
            {
                ans.push_back(pair);
                current++;
            }
            else if(pair[0] >= ans[current - 1][0] && pair[0] <= ans[current - 1][1]) 
            {
                ans[current - 1][1] = max(pair[1], ans[current - 1][1]);
            }
        }

        return ans;  
    }

    static bool compareFirstElement(vector<int>& a, vector<int>& b)
    {
        return a[0] < b[0];
    }
};