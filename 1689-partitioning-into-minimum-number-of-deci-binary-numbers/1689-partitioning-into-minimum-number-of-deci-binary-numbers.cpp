const int ZERO = [](){
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
return 0;
}();
class Solution {
public:
    int minPartitions(string n) 
    {
        int ans = 0;
        for (char ch : n)
        {
            ans = max(ans, ch - '0');
            if (ans == 9) 
                break;
        }
        return ans;
    }
};