class Solution {
public:
    int recurse(vector<int>& nums,vector<int>& dp,int ind){
        if(ind>=nums.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];

        //include
        dp[ind]= max(nums[ind]+recurse(nums,dp,ind+2),recurse(nums,dp,ind+1));
        return dp[ind];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);

        return recurse(nums,dp,0);
    }
};