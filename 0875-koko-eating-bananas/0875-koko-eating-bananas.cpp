const int ZERO = [](){
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
return 0;
}();
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int maxPile = 0;

        for(const auto& num: piles)
            maxPile = max(maxPile, num);

        long long l = 1;
        long long r = maxPile;
        long long ans = maxPile;

        while(l <= r)
        {
            long long mid = l + (r - l) / 2;

            if(findK(piles, mid) <= h)
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }

        return static_cast<int>(ans);
    }

    long long findK(const vector<int>& piles, long long k)
    {
        long long totalTime = 0;

        for(int i = 0; i < piles.size(); i++)
        {
            totalTime += (piles[i] + k - 1) / k;
        }

        return totalTime;
    } 
};
