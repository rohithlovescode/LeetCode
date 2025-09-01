class Solution {
public:
    void solve(vector<int>& div, int ind, vector<int>& ans, vector<int>& temp,int prod,int n,int k,int mini, int maxi,int &currAns){
        if(ind>=div.size()|| prod>n){
            return;
        }
        if(k==0){
            if(prod==n&&(maxi-mini)<currAns){
                ans=temp;
                currAns=(maxi-mini);
            }
            return;
        }
        temp.push_back(div[ind]);
        
        if (prod <= n / div[ind]) {
            solve(div, ind, ans, temp, prod * div[ind], n, k - 1, min(mini, div[ind]), max(maxi, div[ind]), currAns);
        }

        temp.pop_back();
        solve(div,ind+1,ans,temp,prod,n,k,mini,maxi,currAns);
    }
    vector<int> minDifference(int n, int k) {
        vector<int> divisors;
        vector<int> ans;
        vector<int> temp;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                divisors.push_back(i);
                if(n/i!=i)
                divisors.push_back(n/i);
            }
        }
        sort(divisors.begin(),divisors.end());
        
        int currAns=INT_MAX;
        solve(divisors,0,ans,temp,1,n,k,INT_MAX,INT_MIN,currAns);
        return ans;
    }
};