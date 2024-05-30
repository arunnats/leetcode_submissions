class Solution {
public:
    bool isPerfectSquare(int x) 
    {
        long long l = 1;
        long long r = x / 2 + 1; // No need to check beyond this range

        while(l<=r)
        {
            long long mid = (l + r) / 2;
            if(mid * mid == x)
                return true;
            else if(mid * mid > x )
                r = mid - 1;
            else
                l = mid + 1;
        }

        return false;
    }
};