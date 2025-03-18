class Solution {
public:
    int solve(int l,int r,vector<int>& arr,vector<vector<int>>& dp){
        if(l==0||l==arr.size()-1||r==0||r==arr.size()-1){
            return 0;
        }
        else if(dp[l][r]!=-1){
            return dp[l][r];
        }
        int maxi=0;
        for(int i=l;i<=r;i++){
            int currAns=arr[i]*arr[l-1]*arr[r+1]+solve(l,i-1,arr,dp)+solve(i+1,r,arr,dp);
            maxi=max(currAns,maxi);
        }
        dp[l][r]=maxi;
        return dp[l][r];

    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        vector<int> newArr;

        newArr.push_back(1);
        for(int i=0;i<n;i++){
            newArr.push_back(nums[i]);
        }
        newArr.push_back(1);


        int left=1,right=n;
        return solve(left,right,newArr,dp);
    }
};