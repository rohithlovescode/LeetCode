class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(i>0&&nums[i-1]==nums[i]){
                continue;
            }
            int left=i+1;
            int right=n-1;

            while(left<right){
                if(nums[i]+nums[left]+nums[right]==0){
                    ans.push_back({nums[i],nums[left],nums[right]});//vector
                    left++;
                    right--;
                    while(left<n&&nums[left]==nums[left-1]){
                        left++;
                    }
                    while(right>=0&&right<n-1&&nums[right]==nums[right+1]){
                        right--;
                    }
                }
                else if(nums[i]+nums[left]+nums[right]>0){
                    right--;
                    while(right>=0&&right<n-1&&nums[right]==nums[right+1]){
                        right--;
                    }
                }else{
                    left++;
                    while(left<n&&nums[left]==nums[left-1]){
                        left++;
                    }

                }

            }
        }
        return ans;
    }
};