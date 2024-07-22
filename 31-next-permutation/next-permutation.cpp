class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return;
        if(is_sorted(nums.begin(),nums.end())){
            swap(nums[n-1],nums[n-2]);
            return;
        }
        int index = n-1;
        bool found = false;
        for(int i = n-2;i>=0;i--){
            index--;
           if(nums[i]<nums[i+1]){
            found = true;
            break;
           }
        }
        if(index==0 && !found){
            for(int i = 0;i<(n/2);i++){
                swap(nums[i],nums[n-i-1]);
            }
            return;
        }
        int index2 = -1;
        for(int i = n-1;i>index;i--){
            if(nums[i]>nums[index]){
                index2 = i;
                break;
            }
        }
        swap(nums[index],nums[index2]);
        sort(nums.begin()+index+1,nums.end());
    }
};