class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        for(int i=0;i<k;i++){
            while(!dq.empty()&&nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        vector<int> ans;
        ans.push_back(nums[dq.front()]);

        for(int i=k;i<nums.size();i++){
            while(!dq.empty()&&nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            if(!dq.empty()&&dq.front()<=i-k){
                dq.pop_front();
            }
            dq.push_back(i);
            ans.push_back(nums[dq.front()]);

        }

        return ans;

    }
};