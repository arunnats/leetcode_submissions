class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) 
    {
        int n = cardPoints.size();
        int l = n - k;
        int score = 0;
        int ans;

        for(int i = l; i < n; i ++)
        {
            score = score + cardPoints[i];
        }
        ans = score;

        for(int r = 0; r < k; r++)
        {
            score = score + cardPoints[r];
            score = score - cardPoints[l];
            l++;
            ans = max(ans, score);
        }
        
        return ans;
    }
};