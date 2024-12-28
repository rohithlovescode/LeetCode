class Solution {
private:
    void solve(vector<int> nums,int index,vector<int> output,vector<vector<int>>& sol){
        if(index>=nums.size()){
            sol.push_back(output);
            return;
        }
        //for exclude
        solve(nums,index+1,output,sol);
        //for include
        output.push_back(nums[index]);
        solve(nums,index+1,output,sol);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sol;
        vector<int> output;//not completely sure why
        int index=0;
        solve(nums,index,output,sol);
        return sol;
    }
};