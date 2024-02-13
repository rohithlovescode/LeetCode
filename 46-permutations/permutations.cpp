class Solution {
private:
    void solve(vector<int> nums,int index,vector<vector<int>>& sol){
        if(index>=nums.size()){
            sol.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            solve(nums,index+1,sol);
            swap(nums[i],nums[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> sol;
        int index=0;
        solve(nums,index,sol);
        return sol;
    }
};