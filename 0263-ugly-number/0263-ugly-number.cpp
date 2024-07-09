class Solution {
public:
    bool isUgly(int n) 
    {
        if (n <= 0) {
            return false;
        }

        int uglySet[] = {2,3,5};

        for (int num : uglySet)
        {
            while (n % num == 0) 
            {
                n /= num;
            }
        }

        return n == 1;
    }
};