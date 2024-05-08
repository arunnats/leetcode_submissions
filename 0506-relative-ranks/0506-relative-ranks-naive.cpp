class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) 
    {
        int n = score.size();
        vector<pair<int, string>> dictionary(n);
        vector<int> temp;
        vector<string> ans(n);

        for(const auto& val : score)
        {
            temp.push_back(val);
        }

        sort(temp.begin(), temp.end(), greater<int>());

        int current = 1;
        for(const auto& val : temp)
        {
            if(current == 1)
            {
                dictionary[current - 1] = {val, "Gold Medal"};
            }
            else if(current == 2)
            {
                dictionary[current - 1] = {val, "Silver Medal"};
            }
            else if(current == 3)
            {
                dictionary[current - 1] = {val, "Bronze Medal"};
            }
            else
            {
                dictionary[current - 1] = {val, to_string(current)};
            }
            current ++;
        }

        for(int i = 0; i < n; i ++)
        {
            for(int j = 0; j < n; j ++)
            {
                if(score[i] == dictionary[j].first)
                {
                    ans[i] = dictionary[j].second;
                }
            }
        }

        return ans;
    }
};