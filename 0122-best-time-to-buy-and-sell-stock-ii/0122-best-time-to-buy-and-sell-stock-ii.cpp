class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int currMin = INT_MAX;

        for(int i = 0; i < prices.size(); i++){
            if(currMin < prices[i]){
                ans+= (prices[i] - currMin);
                currMin = prices[i];
            }else{
                currMin = min(currMin, prices[i]);
            }
            
        }

        return ans;
    }
};