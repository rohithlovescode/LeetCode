class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 0; 
        }
        
        int jumps = 0;
        int far = 0;
        int cur = 0;
        
        for (int i = 0; i < n - 1; i++) {
            far = max(far, i + nums[i]);
            if (i == cur) {
                jumps++;
                cur = far;
                if (cur >= n - 1) {
                    break;
                }
            }
        }
        
        return jumps;
    }
};