class Solution {
public:
    int binarySearch(int left,int right,vector<int>& nums,int target){
        if(left>right){
            return -1;
        }
        int mid=left+(right-left)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            return binarySearch(left,mid-1,nums,target);
        }else{
            return binarySearch(mid+1,right,nums,target);
        }
    }
    int findPivot(int left, int right, vector<int>& nums) {
    if (left >= right) return left; // Base case

    int mid = left + (right - left) / 2;
    
    if (nums[mid] > nums[right]) { 
        return findPivot(mid + 1, right, nums); // Pivot is in the right half
    } else {
        return findPivot(left, mid, nums); // Pivot is in the left half
    }
}

    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int k=findPivot(0,n-1,nums);
        
        int leftSearch=binarySearch(0,k-1,nums,target);
        if(leftSearch!=-1){
            return leftSearch;
        }
        return binarySearch(k,n-1,nums,target);
    }
};