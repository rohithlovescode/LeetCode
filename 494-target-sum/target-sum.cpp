class Solution {
public:
    int solve(vector<int>& nums, int target, int ind, map<pair<int,int>,int>& ways){
        if(ind==nums.size()){
            return target==0?1:0;
        }
        if(ways.count({ind,target})!=0) return ways[{ind,target}];
        ways[{ind,target}]=solve(nums,target-nums[ind],ind+1,ways)+solve(nums,target+nums[ind],ind+1,ways);
        return ways[{ind,target}];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int,int>,int> ways;
        int n=nums.size();

        return solve(nums, target,0,ways);
    }
};