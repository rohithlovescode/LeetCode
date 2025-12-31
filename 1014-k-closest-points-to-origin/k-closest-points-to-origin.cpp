class compare{
public:
    bool operator()(pair<int,int>& a,pair<int,int> &b){
        return a.first*a.first+a.second*a.second<b.first*b.first+b.second*b.second;
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
        vector<vector<int>> ans;
        for(auto point: points){
            pq.push({point[0],point[1]});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            ans.push_back(vector<int>({top.first,top.second}));
        }
        return ans;
    }
};