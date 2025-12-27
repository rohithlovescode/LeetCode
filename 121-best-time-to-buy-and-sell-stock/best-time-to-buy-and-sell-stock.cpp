class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //rightMax=7
        //ans=5

        int leftMin=INT_MAX;
        int ans=0;

        for(auto& price:prices){
            if(price<leftMin){
                leftMin=price;
            }else{
                ans=max(ans,price-leftMin);
            }
        }
        return ans;
    }
};