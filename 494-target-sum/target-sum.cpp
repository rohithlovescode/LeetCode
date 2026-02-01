class Solution {
public:
    int solve(vector<int>& nums, int target, int ind, vector<unordered_map<int, int>>& ways) {
        if (ind == nums.size()) {
            return target == 0 ? 1 : 0;
        }
        // Check map at specific index
        if (ways[ind].count(target)) return ways[ind][target];

        ways[ind][target] = solve(nums, target - nums[ind], ind + 1, ways) + 
                            solve(nums, target + nums[ind], ind + 1, ways);
        return ways[ind][target];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        // Create a vector where each index holds its own map
        vector<unordered_map<int, int>> ways(nums.size());
        return solve(nums, target, 0, ways);
    }
};