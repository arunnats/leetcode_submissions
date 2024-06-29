class Solution {
public:
    bool isHappy(int n) 
    {
        while(n >= 10)
        {
            int temp = n;
            int sum = 0;
            while(temp > 0)
            {
                int num = temp%10;
                num = num*num;
                sum = sum + num;
                temp = temp/10;
            }
            n = sum;
        }   

        if(n==1 || n==7)
            return true;

        return false;
    }
};