class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int n = temperatures.size();
        stack<int> tempStack;
        vector<int> ans(n, 0);

        for(int i = 0; i < n; i++)
        {
            while(!tempStack.empty() && temperatures[i] > temperatures[tempStack.top()])
            {
                int index = tempStack.top();
                tempStack.pop();
                ans[index] = i - index;
            }
            tempStack.push(i);
        }

        return ans;
    }
};