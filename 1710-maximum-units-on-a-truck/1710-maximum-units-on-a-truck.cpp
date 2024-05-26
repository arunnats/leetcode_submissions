class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) 
    {
        sort(boxTypes.begin(), boxTypes.end(), compare);
        int ans = 0;
        for(int i = 0;i < boxTypes.size(); i++)
        {
            if(boxTypes[i][0] > truckSize)
            {
                ans = ans + truckSize * boxTypes[i][1];
                break;
            }
            else
            {
                ans = ans + boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
        }
        return ans;
    }
    static bool compare(const vector<int>& boxA, const vector<int>& boxB) {
        return boxA[1] > boxB[1];
    }
};