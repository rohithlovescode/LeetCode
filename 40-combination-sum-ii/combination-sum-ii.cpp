class Solution {
public:
    void solve(vector<int>& candidates,int ind,int target,vector<int>& temp,vector<vector<int>>& sol){
        if(target==0){
            sol.push_back(temp);
            return;
        }
        if(ind>=candidates.size()||target<0){
            return;
        }
        temp.push_back(candidates[ind]);
        solve(candidates,ind+1,target-candidates[ind],temp,sol);
        temp.pop_back();
        while (ind + 1 < candidates.size() && candidates[ind] == candidates[ind + 1]) {
            ind++;
        }
        solve(candidates,ind+1,target,temp,sol);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> sol;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        solve(candidates,0,target,temp,sol);
        return sol;
    }
};