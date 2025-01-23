class Solution {
public:
    int solve(int num,vector<int>& nums,map<int,int>& available,int& ans){
        if(available[num+1]==0){
            available[num]=1;
        }else{
            if(available[num+1]==INT_MIN){
                available[num]=solve(num+1,nums,available,ans)+1;
            }else{
                available[num]=available[num+1]+1;
            }
        }
        ans=max(ans,available[num]);
        return available[num];
    }
    int longestConsecutive(vector<int>& nums) {
        
        map<int,int> available;
        for( auto num: nums){
            available[num]=INT_MIN;
        }
        int ans=0;
        for(int i=0;i<nums.size();i++)
            solve(nums[i],nums,available,ans);
        return ans;
    }
};

// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         if(nums.size()==0){
//             return 0;
//         }
//         priority_queue<int> values;

//         for(int i=0;i<nums.size();i++){
//             values.push(nums[i]);
//         }
//         int temp=1,sol=1;
//         int curr=values.top();
//         values.pop();
//         while(!values.empty()){
//             if(values.top()==curr-1){
//                 curr-=1;
//                 temp++;
//             }else if(values.top()==curr){
                
//             }
//             else{
//                 curr=values.top();
//                 temp=1;
//             }
//             values.pop();
//             sol=max(temp,sol);
//         }
//         return sol;
//     }
// };