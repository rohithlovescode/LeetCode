struct minHeap{
    bool operator()(const pair<int,int> &p1, const pair<int,int> &p2){
        return p1.second>p2.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> sol;
        unordered_map<int,int> counts;
        for(int i=0;i<nums.size();i++){
            counts[nums[i]]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>> , minHeap> topK;
        int counter =0;
        for(auto i: counts){
            if(counter<k){
                topK.push(i);// i is a pair
                counter++;

            }
            else if(counter==k&&!topK.empty()&&topK.top().second<i.second){ 
                topK.push(i);
                topK.pop();
            }
        }
        while(!topK.empty()){
            sol.push_back(topK.top().first);
            topK.pop();
        }
        return sol;
    }
};