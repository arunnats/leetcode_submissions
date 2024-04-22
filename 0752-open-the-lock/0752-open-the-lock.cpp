class Solution {
public:
    int openLock(vector<string>& deadends, string target) 
    {
        unordered_set<string> deadSet(deadends.begin(), deadends.end());
        unordered_set<string> vis;

        if (deadSet.count("0000")) 
        {
            return -1;
        }

        queue<pair<string, int>> q;

        q.push({"0000", 0});
        vis.insert("0000");

        while (!q.empty()) 
        {
            pair<string, int> currentPair = q.front();
            q.pop();

            string currentCombination = currentPair.first;
            int moves = currentPair.second;

            if(currentCombination == target)
            {
                return moves;
            }

            for(int i = 0; i < 4; i ++)
            {
                for(int j = 0; j < 2; j++ )
                {
                    int delta;
                    if(j == 0)
                        delta = -1;
                    else 
                        delta = 1; 

                    string newComb = currentCombination;
                    newComb[i] = '0' + (currentCombination[i] - '0' + delta + 10) % 10;

                    if(vis.find(newComb) == vis.end() && deadSet.find(newComb) == deadSet.end())
                    {
                        vis.insert(newComb);
                        q.push({newComb, moves + 1});
                    }
                }
            }
        }

        return -1;
    }
};