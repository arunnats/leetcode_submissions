class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        unordered_map<int, vector<int>> adjList;
        stack<int> ansStack;
        vector<int> ans;

        for(const auto& edge: prerequisites)
        {
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(numCourses, 0);

        for(int i = 0; i < numCourses; i++)
        {
            if(visited[i] == 0)
            {
                if(!DFS(i, adjList, visited, ansStack))
                {
                    return {}; 
                }
            }
        }
    
        while(!ansStack.empty())
        {
            ans.push_back(ansStack.top());
            ansStack.pop();
        }

        return ans;
    }

    bool DFS(int course, unordered_map<int, vector<int>>& adjList, vector<int>& visited, stack<int>& ansStack)
    {
        if (visited[course] == 1)
            return false;

        if (visited[course] == 2) 
            return true;

        visited[course] = 1;

        for (int neighbor : adjList[course])
        {
            if(visited[neighbor] != 2)
            {
                if(!DFS(neighbor, adjList, visited, ansStack))
                {
                    return false; 
                }
            }
        }

        visited[course] = 2; 
        ansStack.push(course);
        return true;
    }
};