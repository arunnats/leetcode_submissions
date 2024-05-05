class Solution {
public:
    string addBinary(string a, string b) 
    {
        int i = a.size()-1;
        int j = b.size()-1;
        int carry = 0;
        string result = "";

        while (i >= 0 || j >= 0 || carry != 0) 
        {
            int sum = carry;

            if (i >= 0) {
                sum += a[i] - '0';  
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0'; 
                j--;
            }

            carry = sum / 2;
            sum = sum % 2;
            result = char('0' + sum) + result;
        }

        return result;
    }
};