class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> sol;

        for(int i=0;i<n-2;i++){

            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int target=-nums[i];
            int left=i+1,right=n-1;
            while(left<right){
                if(left>i+1&&nums[left]==nums[left-1]){
                    left++;
                    continue;
                }
                if(right!=n-1&&nums[right]==nums[right+1]){
                    right--;
                    continue;
                }
                if(nums[left]+nums[right]==target){
                    sol.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                }
                else if(nums[left]+nums[right]<target){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return sol;
    }
};