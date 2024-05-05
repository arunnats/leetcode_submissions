class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        vector<vector<int>> ans;
        vector<pair<vector<int>, double>> distances;

        for (const auto& point : points) 
        {
            double dist = distance(point);
            distances.push_back({point, dist});
        }

        sort(distances.begin(), distances.end(), [](const pair<vector<int>, double>& a, const pair<vector<int>, double>& b) {
            return a.second < b.second;
        });

        for (int i = 0; i < k; ++i) 
        {
            ans.push_back(distances[i].first);
        }
        
        return ans;
    }

    double distance(vector<int> point)
    {
        double x = point[0];
        double y = point[1];
        return sqrt(x*x + y*y);
    }
};