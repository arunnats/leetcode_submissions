class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {   
        int n = isConnected.size();
        vector<int> parent(n);
        vector<int> rank(n, 0);
        
        int ans = n;

        for(int i = 0; i < n; i ++)
        {
            parent[i] = i;  
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(isConnected[i][j] == 1)
                {
                    ans -= unionSet(i, j, parent, rank);
                }
            }
        }

        return ans;
    }

    int find(int node, vector<int>& parent)
    {
        if (node != parent[node])
        {
            parent[node] = find(parent[node], parent); 
        }
        return parent[node];
    }

    int unionSet(int node1, int node2, vector<int>& parent, vector<int>& rank)
    {
        int p1 = find(node1, parent);
        int p2 = find(node2, parent);

        if(p1 == p2)
            return 0;
        
        if(rank[p1] > rank[p2])
        {
            parent[p2] = p1;
        }
        else if(rank[p1] < rank[p2])
        {
            parent[p1] = p2;
        }
        else
        {
            parent[p2] = p1;
            rank[p1]++;
        }
        return 1;
    }
};
