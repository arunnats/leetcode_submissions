class TimeMap {
    unordered_map<string, vector<pair<int, string>>> hMap;
public:
    TimeMap() 
    {
    }
    
    void set(string key, string value, int timestamp) 
    {
        hMap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) 
    {
        vector<pair<int, string>>& pairList = hMap[key];
        int n = pairList.size();

        string ans;

        int l = 0;
        int r = n - 1;

        while( l <= r )
         {
            int mid = l + (r - l) / 2;
            if (pairList[mid].first <= timestamp)
            {
                ans = pairList[mid].second;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
            
        }

        return ans;
    }
};