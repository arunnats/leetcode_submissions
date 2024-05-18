class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        int n=position.size();
        vector<pair<int,int>> pairList;

        for(int i=0; i<n; i++)
        {
            pairList.push_back({position[i],speed[i]});
        }

        sort(pairList.begin(),pairList.end());

        int count = 0;
        double maxTime = INT_MIN;

        for(int i = n-1; i>=0; i--)
        {
            double time = (target-pairList[i].first)*1.0/pairList[i].second;
            if(time>maxTime)
            {
                count++;
                maxTime=time;
            }
        }

         return count;

    }
};