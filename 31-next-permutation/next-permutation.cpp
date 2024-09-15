class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int swapInd;
        for(int i=n-1;i>=0;i--){
            if(i==0){
                sort(nums.begin(),nums.end());
                return;
            }
            if(nums[i-1]<nums[i]){
                swapInd=i-1;
                break;
            }
        }
        for(int i=n-1;i>swapInd;i--){
            if(nums[i]>nums[swapInd]){
                swap(nums[i],nums[swapInd]);
                break;
            }
        }
        sort(nums.begin()+swapInd+1,nums.end());
        return;
    }
};