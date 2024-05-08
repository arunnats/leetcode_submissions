class Solution 
{
public:
    vector<string> findRelativeRanks(vector<int>& score) 
    {
        int n = score.size();
        unordered_map<int, string> rankMapping;
        vector<int> temp = score;
        vector<string> ans(n);

        sort(temp.begin(), temp.end(), greater<int>());

        for (int current = 1; current <= temp.size(); current++) 
        {
            if(current == 1)
            {
                rankMapping[temp[current-1]] = "Gold Medal";
            }
            else if(current == 2)
            {
                rankMapping[temp[current-1]] = "Silver Medal";
            }
            else if(current == 3)
            {
                rankMapping[temp[current-1]] = "Bronze Medal";
            }
            else
            {
                rankMapping[temp[current-1]] = to_string(current);
            }
        }

        for (int i = 0; i < n; i++) 
        {
            ans[i] = rankMapping[score[i]];
        }

        return ans;
    }
};
