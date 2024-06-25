class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        unordered_map<int, vector<int>> adjList;

        for(const auto& edge: prerequisites)
        {
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(numCourses, 0);

        for(int i = 0; i < numCourses; ++i)
        {
            if (visited[i] == 0) 
            {
                if (DFS(i, adjList, visited))
                    return false; 
            }
        }
        return true;
    }

    bool DFS(int course, unordered_map<int, vector<int>>& adjList, vector<int>& visited)
    {
        if (visited[course] == 1)
            return true;
        visited[course] = 1;

        for (int neighbor : adjList[course])
        {
            if (visited[neighbor] != 2) 
            {
                if (DFS(neighbor, adjList, visited))
                    return true;
            }
        }

        visited[course] = 2;
        return false;
    }
};