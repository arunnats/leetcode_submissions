class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>> ans(n);
        vector<vector<int>> graph(n);

        for(const auto& edge: edges)
        {
            graph[edge[0]].push_back(edge[1]);
        }

        for(int i = 0; i < n; i++)
        {
            vector<bool> visit(n, false);
            dfs(graph, i, i, ans, visit);
        }

        return ans;
    }

    void dfs(vector<vector<int>>& graph, int parent, int curr, vector<vector<int>>& ans, vector<bool>& visit) 
    {
        visit[curr] = true;

        for(int dest: graph[curr])
        {
            if (!visit[dest])
            {
                if(!visit[dest])
                {
                    ans[dest].push_back(parent);
                    dfs(graph, parent, dest, ans, visit);
                }
            }
        }
    }
};