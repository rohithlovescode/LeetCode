class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            int ind=(i+nums[i]+100*n)%n;
            ans[i]=nums[ind];
        }
        return ans;
    }
};