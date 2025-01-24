class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefixSum(n);
        prefixSum[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prefixSum[i]=prefixSum[i-1]+nums[i];
        }
        int sum=0;
        for(int i=0;i<n;i++){
            int startInd=max(0,i-nums[i]);
            if(startInd==0){
                sum+=prefixSum[i];
            }else{
                sum+=prefixSum[i];
                sum-=prefixSum[startInd-1];
            }
        }
        return sum;
    }
};