class Solution {
public:
    int nextGreaterElement(int n) 
    {
        vector<int> num;
        int temp = n;
        while(temp > 0)
        {
            num.push_back(temp % 10);
            temp = temp / 10;
        }    
        reverse(num.begin(), num.end()); 

        int size = num.size();
        int i = size - 2;

        while(i >= 0 && num[i] >= num[i + 1])
        {
            i--;
        }

        if (i >= 0)
        {
            int j = size - 1;
            while (j >= 0 && num[j] <= num[i])
            {
                j--;
            }
            swap(num[i], num[j]);
        }
        reverse(num.begin() + i + 1, num.end());

        long long ans = 0;
        for (int digit : num)
        {
            ans = ans * 10 + digit;
        }

        if (ans > INT_MAX || ans <= n)
            return -1;
        else 
            return static_cast<int>(ans);
    }
};