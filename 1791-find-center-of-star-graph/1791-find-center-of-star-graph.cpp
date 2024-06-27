class Solution {
public:
    int findCenter(vector<vector<int>>& edges) 
    {
        vector<int> edge1 = edges[0];
        vector<int> edge2 = edges[1];

        for(const auto& node1: edge1)
        {
            for(const auto& node2: edge2)
            {
                if(node1 == node2)
                    return node1;
            }
        }

        return 0;
    }
};