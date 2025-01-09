class Solution {
public:
    void solve(vector<int>& nums,int ind,vector<int> temp,vector<vector<int>>& sol){
        if(ind==nums.size()){
            sol.push_back(temp);
            return;
        }

        //include
        temp.push_back(nums[ind]);
        solve(nums,ind+1,temp,sol);
        temp.pop_back();
        while(ind<nums.size()-1){
            if(nums[ind+1]==nums[ind]){
                ind++;
            }else{
                break;
            }
        }
        solve(nums,ind+1,temp,sol);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(),nums.end());
        vector<vector<int>> sol;
        solve(nums,0,temp,sol);
        return sol;
    }
};