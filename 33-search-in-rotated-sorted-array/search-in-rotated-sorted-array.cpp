class Solution {
public:
    int modifiedBS(vector<int>& nums, int target,int left,int right){
        if(left>right){
            return -1;
        }
        int mid=left+(right-left)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[left]<nums[right]){
            if(target>nums[mid]){
                return modifiedBS(nums,target,mid+1,right);
            }else{
                return modifiedBS(nums,target,left,mid-1);
            }
        }else{
            if(target>=nums[left]&&(target<nums[mid]||nums[mid]<=nums[right])){
                return modifiedBS(nums,target,left,mid-1);
            }else if((target>=nums[left]&&target<nums[mid])||(nums[mid]<nums[right]&&target<nums[mid])){
                return modifiedBS(nums,target,left,mid-1);
            }
            else{
                return modifiedBS(nums,target,mid+1,right);
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return modifiedBS(nums,target,0,nums.size()-1);
    }
};