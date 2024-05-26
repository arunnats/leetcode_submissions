class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> m;  

        for(int bill : bills) {
            if (bill == 5) {
                m[5]++;
            } else if (bill == 10) {
                if (m[5] > 0) {
                    m[5]--;
                    m[10]++;
                } else {
                    return false;
                }
            } else if (bill == 20) {
                if (m[10] > 0 && m[5] > 0) {
                    m[10]--;
                    m[5]--;
                } else if (m[5] >= 3) {
                    m[5] -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
