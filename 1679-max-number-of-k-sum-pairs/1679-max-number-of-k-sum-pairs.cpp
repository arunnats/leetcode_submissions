class Solution {
public:
    int maxOperations(vector<int>& nums, int k) 
    {
        int ans  = 0;
        int n = nums.size();
        unordered_map<int, int> map;

        for(int i = 0; i < n; i++){
            if(map[k - nums[i]] > 0){
                ans++;
                map[k - nums[i]]--;
            }
            else{
                map[nums[i]]++;
            }
        }

        return ans;
    }
};