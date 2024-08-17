class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        priority_queue<int> values;

        for(int i=0;i<nums.size();i++){
            values.push(nums[i]);
        }
        int temp=1,sol=1;
        int curr=values.top();
        values.pop();
        while(!values.empty()){
            if(values.top()==curr-1){
                curr-=1;
                temp++;
            }else if(values.top()==curr){
                
            }
            else{
                curr=values.top();
                temp=1;
            }
            values.pop();
            sol=max(temp,sol);
        }
        return sol;
    }
};