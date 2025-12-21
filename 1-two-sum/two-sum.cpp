class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mapp;//1->val, 2->ind

        for(int i=0;i<nums.size();i++){
            int val=nums[i];
            if(mapp.count(target-val)!=0){
                int pairInd=mapp[target-val];
                return {pairInd,i};
            }

            mapp[val]=i;
        }

        return {-1,-1};

    }
};