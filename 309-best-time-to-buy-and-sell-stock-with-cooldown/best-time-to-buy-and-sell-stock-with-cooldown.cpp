class Solution {
public:
    int recurse(int ind,vector<int> & prices,vector<int> &dp1,vector<int>& dp2, 
        bool isPurchased){
        
        if(ind>=prices.size()){
            return 0;
        }
        if(isPurchased){
            if(dp2[ind]!=-1){
                return dp2[ind];
            }
                int sold=prices[ind]+recurse(ind+2,prices,dp1,dp2,false);
                int pass=recurse(ind+1,prices,dp1,dp2,true);

                dp2[ind]=max(sold,pass);
                return dp2[ind];

        }else{//stock not purchased
            if(dp1[ind]!=-1){
                return dp1[ind];
            }
            int buy=-prices[ind]+recurse(ind+1,prices,dp1,dp2,true);
            int skip=recurse(ind+1,prices,dp1,dp2,false);
            dp1[ind]=max(buy,skip);
            return dp1[ind];
        }

    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        vector<int> dp1(n,-1),dp2(n,-1);
        //dp1 -> stock hasn't been purchased yet
        //dp2 -> stock was purchased
        bool isPurchased=false;
        return recurse(0,prices,dp1,dp2,isPurchased);
    }
};