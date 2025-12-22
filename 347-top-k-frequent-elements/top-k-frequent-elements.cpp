class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mapp;
        int n=nums.size();

        for(auto & num: nums){
            mapp[num]++;
        }

        vector<vector<int>> buckets(n+1,vector<int>());
        vector<int> ans;

        for(auto& pair:mapp){
            buckets[pair.second].push_back(pair.first);
        }


        for(int i=n;i>=0&&ans.size()<k;i--){
            for(auto& num:buckets[i]){
                ans.push_back(num);
            }
        }
        return ans;

    }
};