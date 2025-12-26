class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        // [0 3 2 1]

        // map
        // 0: 4
        // 3: 4
        // 2: 2
        // 1: 1+(1)+(2)=4
        unordered_map<int,int> boundaryCheck;
        int ans=0;
        for(auto num: nums){
            if(boundaryCheck.count(num)!=0){
                continue;
            }
            
            int leftConsecutive=0;
            int rightConsecutive=0;
            if(boundaryCheck.count(num-1)!=0){
                leftConsecutive=boundaryCheck[num-1];
            }
            if(boundaryCheck.count(num+1)!=0){
                rightConsecutive=boundaryCheck[num+1];
            }
            boundaryCheck[num]=leftConsecutive+rightConsecutive+1;
            boundaryCheck[num-leftConsecutive]=boundaryCheck[num];
            boundaryCheck[num+rightConsecutive]=boundaryCheck[num];
            ans=max(ans,boundaryCheck[num]);




        }
        return ans;
    }
};