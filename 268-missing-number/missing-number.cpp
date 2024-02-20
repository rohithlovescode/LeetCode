class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]+1){
                return nums[i]-1;
            }
        }
        if(nums[0]!=0){
            return 0;
        }
        return nums[n-1]+1;
    }
};