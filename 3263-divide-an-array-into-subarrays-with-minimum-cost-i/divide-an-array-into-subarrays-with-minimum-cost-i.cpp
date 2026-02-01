class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int sArrCnt=nums[0];
        int cost=nums[0];
        int mini1=INT_MAX,mini2=INT_MAX;
        mini1=nums[1];

        for(int i=2;i<nums.size();i++){
            if(mini2>nums[i]){
                mini2=nums[i];
                if(mini2<mini1) swap(mini1,mini2);
            }
        }

        return cost+mini1+mini2;
    }
};