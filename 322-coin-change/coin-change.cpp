class Solution {
    map<int,int> dp;
    int solve(vector<int> &coins, int amount){
        if(amount==0){
            return 0;
        }
        if(amount<0){
            return INT_MAX;
        }
        if (dp[amount]!=0){
            return dp[amount];
        }
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){

            int temp=solve(coins,amount-coins[i]);
            if(temp!=INT_MAX)
                mini=min(temp+1,mini);
        }
        dp[amount]=mini;
        return mini;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans=solve(coins,amount);
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};