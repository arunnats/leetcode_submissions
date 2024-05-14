class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int ans = 0;
        int count = 0;
        int flip = k;

        while (r < nums.size())
        {
            if(nums[r] == 1)
            {
                count++;
                r++;
            }
            else if(nums[r] == 0 && flip > 0)
            {
                flip--;
                count++;
                r++;
            }
            else
            {
                while(flip == 0)
                {
                    if(nums[l] == 0)
                    {
                        flip++;
                        l++;
                        count--;
                    }
                    else
                    {
                        l++;
                        count--;
                    }
                }
            }
            ans = max(ans, count);
        }

        return ans;
    }
};