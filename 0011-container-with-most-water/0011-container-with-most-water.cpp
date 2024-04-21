class Solution {
public:
    int maxArea(vector<int>& height) 
    {  
        int ans = 0;
        int start = 0;
        int end = height.size()-1;

        while(start < end)
        {
            int currentArea = (end - start) * min(height[start], height[end]);
            ans = max(ans, currentArea);

            if (height[start] < height[end]) 
            {
                start++;
            } 
            else 
            {
                end--;
            }

        }

        return ans;
    }
};