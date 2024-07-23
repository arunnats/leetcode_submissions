class Solution {
public:
    static unordered_map<int, int> freqMap;

    vector<int> frequencySort(vector<int>& nums) {
        freqMap.clear(); 

        for(const auto& num: nums) {
            freqMap[num]++;
        }    

        sort(nums.begin(), nums.end(), customSort);

        return nums;
    }

    static bool customSort(int a, int b) {
        if (freqMap[a] == freqMap[b]) {
            return a > b; 
        } else {
            return freqMap[a] < freqMap[b]; 
        }
    }
};

unordered_map<int, int> Solution::freqMap; 
