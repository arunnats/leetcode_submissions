class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        if (points.empty()) 
            return 1;

        vector<vector<int>> merged;
        sort(points.begin(), points.end(), compareFirstElement);
        
        int current = 0;
        for(const auto& pair: points)
        {
            if (current == 0)
            {
                merged.push_back(pair);
                current++;
            }
            else if(pair[0] > merged[current - 1][0] && pair[0] > merged[current - 1][1])
            {
                merged.push_back(pair);
                current++;
            }
            else if(pair[0] >= merged[current - 1][0] && pair[0] <= merged[current - 1][1]) 
            {
                merged[current - 1][0] = min(pair[0], merged[current - 1][0]);
                merged[current - 1][1] = min(pair[1], merged[current - 1][1]);
            }
        }

        return merged.size();
    }

    static bool compareFirstElement(vector<int>& a, vector<int>& b)
    {
        return a[0] < b[0];
    }
};