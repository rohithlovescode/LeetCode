class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int count=1;
        int index=1;
        for(int i=1;i<n;i++){
            if(nums[i-1]==nums[i]){
                count++;
            }
            else{
                count=1;
            }
            if(count<=2){
                if(nums[index]!=nums[i])
                nums[index]=nums[i];
                index++;
            }
        }
        return index;
    }
};