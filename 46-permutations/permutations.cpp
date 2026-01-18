class Solution {
public:
    void solve(vector<int>& nums,int ind,vector<vector<int>> &sol){
        if(ind==nums.size()){
            sol.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[i],nums[ind]);
            solve(nums,ind+1,sol);
            swap(nums[i],nums[ind]);
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        int ind=0;
        vector<vector<int>> sol;
        
        solve(nums,ind,sol);
        return sol;
    }
};