class Solution {
public:
    int minAllOneMultiple(int k) {
        int temp=0;
        int ans=1;
        for(ans=1;ans<=k;ans++){
            temp=(temp*10+1)%k;
            if(temp==0){
                return ans;
            }
        }

        return -1;
    }
};