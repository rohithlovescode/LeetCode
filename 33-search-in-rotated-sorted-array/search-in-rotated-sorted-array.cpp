class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;


        while(l<=r){
            int mid=l+(r-l)/2;
            //to avoid out of bounds
            if(nums[mid]==target){
                return mid;
            }

            //condition if elements b/w l and r are sorted
            if(nums[l]<nums[r]){
                if(nums[mid]<target){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
            else{//if elements b/w l and r are not sorted

                
                if(nums[mid]>=nums[l]){
                    //this means l to mid is sorted
                    if(target>=nums[l]&&target<nums[mid]){
                        r=mid-1;
                    }else{
                        l=mid+1;
                    }
                }else{
                    //this means mid to r is sorted
                    if(nums[mid]<target && target<=nums[r]){
                        l=mid+1;
                    }else{
                        r=mid-1;
                    }
                }

            }
        }

        return -1;



    }

    /*
    [4,5 ,6,7,0]

    [7, 0 , 1, 2]]
    */
};