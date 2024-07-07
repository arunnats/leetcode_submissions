class Solution {
public:
    int maxVowels(string s, int k) 
    {
        int n = s.length();
        int ans = 0;
        int count = 0;

        for (int i = 0; i < k; i++) {
            if (checkVowel(s[i])) {
                count++;
            }
        }
        ans = count;

        for (int i = k; i < s.size(); ++i){
            if (checkVowel(s[i])) {
                count++;
            }
            if (checkVowel(s[i - k])) {
                count--;
            }
            ans = max(ans, count);
        }

        return ans;
    }

    bool checkVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
};