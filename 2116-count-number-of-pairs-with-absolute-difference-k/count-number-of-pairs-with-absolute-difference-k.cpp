class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int ans=0;
        unordered_map<int,int> freq;
        for(auto num: nums){
            if(freq.count(num-k)!=0) ans+=freq[num-k];
            if(freq.count(num+k)!=0) ans+=freq[num+k];
            freq[num]++;
        }

        return ans;
    }
};