const int ZERO = [](){
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
return 0;
}();
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        while (l < r) 
        {
            int mid = l + (r - l) / 2;
            if(canFinish(piles, mid, h))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
    
    bool canFinish(vector<int>& piles, int k, int h)
    { 
        int hours = 0;
        for(const auto& pile : piles)
        {
            int x = pile / k;
            hours = hours + x;
            if(pile % k != 0)
                hours++;
        }
        return hours <= h;
    }
};
