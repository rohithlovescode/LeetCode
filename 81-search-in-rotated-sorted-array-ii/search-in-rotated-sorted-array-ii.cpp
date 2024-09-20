class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target)
            return true;
            if((nums[s]==nums[mid])&&(nums[mid]==nums[e])){
                s++;
                e--;
            }
            else if(nums[s]<=nums[mid]){
                if((target>=nums[s])&&(target<nums[mid])){
                    e=mid-1;
                }else{
                    s=mid+1;
                }
            }
            else{
                if(nums[mid]<target&&target<=nums[e]){
                    s=mid+1;
                }else{
                    e=mid-1;
                }
            }
        }return false;
    }
};
// class Solution {
// public:
//     int findPivot(vector<int>& nums){
//         int s=0;
//         int e=nums.size()-1;
//         while(s<e){
//             int mid=s+(e-s)/2;
//             if(nums[s]==nums[mid]&&nums[mid]==nums[e]){
//                 s++;
//                 e--;
//             }else if(nums[s]==nums[mid]){
//                 s=mid+1;
//             }
//             else if(nums[s]>nums[mid]){
//                 e=mid;
//             }else{
//                 e=mid;
//             }
//         }
//         return s;
//     }
//     bool binarySearch(vector<int>& nums,int s, int e,int target){
//         while(s<=e){
//             int mid=s+(e-s)/2;
//             if(nums[mid]==target){
//                 return true;
//             }else if(nums[mid]>target){
//                 e=mid-1;
//             }else{
//                 s=mid+1;
//             }
//         }
//         return false;
//     }
//     bool search(vector<int>& nums, int target) {
//         int pivot=findPivot(nums);
//         if(target>=nums[pivot]&&target<=nums[nums.size()-1]){
//             return binarySearch(nums,pivot,nums.size()-1,target);
//         }else{
//             return binarySearch(nums,0,pivot-1,target);
//         }
//     }
// };