class Solution {
public:
    string simplifyPath(string path) 
    {
        int n = path.size();
        stack <string> wordStack; 
        int wordStart = 0;

        for (int i = 1; i < n; i++) 
        {
            if (path[i] == '/') 
            {
                if (i > wordStart + 1) 
                {
                    string segment = path.substr(wordStart + 1, i - wordStart - 1);
                    if (segment == "..") 
                    {
                        if (!wordStack.empty()) wordStack.pop();
                    } 
                    else if (segment != "." && !segment.empty()) 
                    {
                        wordStack.push(segment);
                    }
                }
                wordStart = i;
            }
        }

        if (wordStart < n - 1) 
        {
            string segment = path.substr(wordStart + 1);
            if (segment == "..") 
            {
                if (!wordStack.empty()) wordStack.pop();
            } 
            else if (segment != "." && !segment.empty()) 
            {
                wordStack.push(segment);
            }
        }

        string simplifiedPath;
        while (!wordStack.empty()) 
        {
            simplifiedPath = "/" + wordStack.top() + simplifiedPath;
            wordStack.pop();
        }

        return simplifiedPath.empty() ? "/" : simplifiedPath;
    }   
};