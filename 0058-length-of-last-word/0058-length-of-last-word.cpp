class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        int n = s.length();
        int count = 0 ;

        while (n-1 >= 0 && s[n-1] == ' ')
            n--;

        while (n-1 >= 0 && s[n-1] != ' ') {
            count++;
            n--;
        }

        return count;
    }
};