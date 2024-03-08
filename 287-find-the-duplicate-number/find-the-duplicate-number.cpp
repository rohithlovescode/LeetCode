class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int sum=0;
        
        int size=nums.size();
        vector<int> count(size,0);
        for(int i=0;i<size;i++){
            if(count[nums[i]]==0){
                count[nums[i]]++;
            }else{
                return nums[i];
            }
        }
        return 0;
    }
};