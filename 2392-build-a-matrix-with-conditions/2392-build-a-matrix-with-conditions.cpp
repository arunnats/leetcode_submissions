class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rowOrder = topologicalSort(k, rowConditions);
        vector<int> colOrder = topologicalSort(k, colConditions);

        if (rowOrder.empty() || colOrder.empty()) {
            return {}; 
        }
        
        unordered_map<int, int> rowPos, colPos;
        for (int i = 0; i < k; ++i) {
            rowPos[rowOrder[i]] = i;
            colPos[colOrder[i]] = i;
        }
        
        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for (int i = 1; i <= k; ++i) {
            matrix[rowPos[i]][colPos[i]] = i;
        }
        
        return matrix;
    }

    vector<int> topologicalSort(int k, const vector<vector<int>>& conditions) {
        vector<int> inDegree(k + 1, 0);
        unordered_map<int, vector<int>> graph;
        
        for (const auto& cond : conditions) {
            int u = cond[0];
            int v = cond[1];
            graph[u].push_back(v);
            inDegree[v]++;
        }
        
        queue<int> q;
        for (int i = 1; i <= k; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> topoOrder;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topoOrder.push_back(node);
            
            for (int neighbor : graph[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        if (topoOrder.size() == k) {
            return topoOrder;
        } else {
            return {};
        }
    }
};