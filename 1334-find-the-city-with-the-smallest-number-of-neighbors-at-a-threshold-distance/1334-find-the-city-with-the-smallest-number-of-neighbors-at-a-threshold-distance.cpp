class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int, vector<pair<int, int>>> adjList;

        vector<vector<int>> matrix (n, vector<int>(n, INT_MAX));

        for(int i = 0; i < n; i++){
            matrix[i][i] = 0;
        }

        for(const auto& edge: edges){
            matrix[edge[0]][edge[1]] = edge[2];
            matrix[edge[1]][edge[0]] = edge[2];
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (matrix[i][k] != INT_MAX && matrix[k][j] != INT_MAX && matrix[i][j] > matrix[i][k] + matrix[k][j]) {
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                    }
                }
            }
        }
        
        int city = -1;
        int minReachableCities = n;

        for (int i = 0; i < n; i++) {
            int reachableCities = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && matrix[i][j] <= distanceThreshold) {
                    reachableCities++;
                }
            }

            if (reachableCities < minReachableCities) {
                minReachableCities = reachableCities;
                city = i;
            } else if (reachableCities == minReachableCities) {
                city = max(city, i);
            }
        }

        return city;
    }
};