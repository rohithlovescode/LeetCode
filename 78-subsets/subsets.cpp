class Solution {
public:
    void backtrack(int ind, vector<vector<int>> &ans,vector<int>& curr, vector<int>& nums){
        if(ind>=nums.size()){
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[ind]);
        backtrack(ind+1,ans,curr,nums);

        curr.pop_back();
        backtrack(ind+1,ans,curr,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        int ind=0;

        backtrack(ind,ans,curr,nums);
        return ans;
    }
};