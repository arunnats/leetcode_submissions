class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) 
    {
        int ans = 0;

       
        while(numOnes > 0 && k > 0)
        {
            ans++;
            numOnes--;
            k--;
        }
        while(numZeros > 0 && k > 0)
        {
            numZeros--;
            k--;
        }
        while(numNegOnes > 0 && k > 0)
        {
            ans--;
            numNegOnes--;
            k--;
        }
        

        return ans;
    }
};