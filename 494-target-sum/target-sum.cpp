class Solution {
public:
    void recurse(int currSum, int  ind, vector<int>& nums, int target,int& ans){
        if(ind==nums.size()){
            if(currSum==target){
                ans++;
            }
            return;
        }

        recurse(currSum+nums[ind],ind+1,nums,target,ans);
        recurse(currSum-nums[ind],ind+1,nums,target,ans);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans=0,currSum=0;
        recurse(currSum,0,nums,target,ans);
        return ans;
    }
};