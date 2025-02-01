class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> minh; 
        for (int i = 0; i < points.size(); i++) {
            minh.push({pow(points[i][0],2) + pow(points[i][1],2), i}); 
        }
        while (k-- > 0 && !minh.empty()) {
            res.push_back({points[minh.top().second][0], points[minh.top().second][1]});
            minh.pop();
        }
        return res;
    }
};