class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast=0;
        int slow=0;
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(fast!=slow);
        slow=0;
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
        
    }
};