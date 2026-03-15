class Solution {
public:
    int arrangeCoins(int n) {
        int left=1;
        int right=sqrt(n)*sqrt(2)+1;
        int ans=1;

        while(left<=right){
            long mid=left+(right-left)/2;
            if(mid*(mid+1)/2 <= n){
                left=mid+1;
                ans=mid;
            }else{
                right=mid-1;
            }
        }
        return ans;
    }
};