class Solution {
public:
    bool validPair(long long rem,vector<int>& nums,int ind, map<pair<int,int>,bool>& dp){
        if(rem==0) return true;
        if(rem<0||ind>=nums.size()) return false;
        if(dp.count({rem,ind})!=0) return dp[{rem,ind}];

        dp[{rem,ind}] = validPair(rem-nums[ind],nums,ind+1,dp)||validPair(rem,nums,ind+1,dp);
        return dp[{rem,ind}];
    }
    bool canPartition(vector<int>& nums) {
        long long sum=0;
        for(auto num: nums){
            sum+=num;
        }
        if(sum%2==1) return false;
        map<pair<int,int>,bool> dp;

        return validPair(sum/2,nums,0,dp);
    }
};