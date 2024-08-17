class Solution {
public:
    int binarySearch(vector<int>& nums,int start,int end, int target){
        int mid=start+(end-start)/2;
        if(start>end){
            return -1;
        }
        if(nums[mid]==target){
            return mid;
        }else if(nums[mid]<target){
            return binarySearch(nums,mid+1,end,target);
        }
        else{
            return binarySearch(nums,start,mid-1,target);
        }
    }
    int search(vector<int>& nums, int target) {
        return binarySearch(nums,0,nums.size()-1,target);
    }
};