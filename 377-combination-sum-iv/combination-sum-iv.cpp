class Solution {
public:
    int solve(vector<int>& nums, int target, vector<int>& dp){
        if(target<0){
            return 0;
        }
        else if(target==0){
            return 1;
        }
        else if(dp[target]!=-1){
            return dp[target];
        }
        int temp=0,n=nums.size();
        for(int i=0;i<n;i++){
            temp=temp+solve(nums,target-nums[i],dp);
        }
        dp[target]=temp;
        return temp;

    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return solve(nums,target,dp);
    }
};