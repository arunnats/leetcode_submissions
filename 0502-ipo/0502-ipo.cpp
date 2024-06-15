class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) 
    {
        int n = profits.size();
        vector <pair<int, int>> pairList;

        for (int i = 0; i < n; ++i) 
        {
            pair <int, int> temp = {capital[i], profits[i]};
            pairList.push_back(temp);
        }

        sort(pairList.begin(), pairList.end());

        priority_queue<int> maxHeap;
        int idx = 0;

        for(int j = 0; j < k; j++)
        {
            while(idx < n && pairList[idx].first <= w)
            {
                maxHeap.push(pairList[idx].second);
                idx++;
            }

            if(maxHeap.empty())
            {
                break;
            }

            w = w + maxHeap.top();
            maxHeap.pop();
        }

        return w;
    }
};