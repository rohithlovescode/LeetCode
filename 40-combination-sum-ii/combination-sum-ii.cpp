class Solution {
public:
    void backtrack(vector<int>& candidates,int ind,int target, vector<vector<int>>& ans,vector<int>& curr){
        
        if(target==0){
            ans.push_back(curr);
            return;
        }
        if(ind>=candidates.size()||target-candidates[ind]<0) return;

        curr.push_back(candidates[ind]);
        backtrack(candidates,ind+1,target-candidates[ind],ans,curr);
        curr.pop_back();

        while(ind+1<candidates.size()&&candidates[ind+1]==candidates[ind]){
            ind++;
        }
        backtrack(candidates,ind+1,target,ans,curr);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        // backtrack
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(candidates,0,target,ans,curr);


        return ans;
    }
};