class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt = 0;
        int ans = 0;

        for(const auto& g: gain) {
            alt = alt + g;
            ans = max(ans, alt); 
        }
        
        return ans;
    }
};