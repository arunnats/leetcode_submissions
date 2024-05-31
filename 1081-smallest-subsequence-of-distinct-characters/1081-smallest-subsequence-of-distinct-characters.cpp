class Solution {
public:
    string smallestSubsequence(string s) 
    {
        vector<int> li(26,0);
        vector<bool> vis(26,false);
        string ans="";
        stack<char> charStack;
        
        for(int i=0; i<s.size(); i++)
        {
          li[s[i]-'a'] = i;
        }

        for(int i=0; i<s.length(); i++)
        {
          int curr=s[i]-'a';
          if(vis[curr])  continue;
          while(charStack.size()>0 && charStack.top()>s[i] && i<li[charStack.top()-'a'])
          {
              vis[charStack.top()-'a']=false;
              charStack.pop();
          }
          charStack.push(s[i]);
          vis[curr]=true;
        }

        while(!charStack.empty())
        {
          ans = charStack.top() + ans;
          charStack.pop();
        }
        return ans;
    }
};