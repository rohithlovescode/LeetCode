class Solution {
public:
    int numDecodings(string s) {
        int leng=s.length();
        vector<int> dp(leng+1,-1);

        dp[leng-1]=s[leng-1]=='0'?0:1;
        dp[leng]=1;

        for(int i=leng-2;i>=0;i--){
            if(s[i]=='0') dp[i]=0;
            else{
                if(s[i]<'2'||(s[i]=='2'&&s[i+1]<='6')){
                    dp[i]=dp[i+2]+dp[i+1];
                }else{
                    dp[i]=dp[i+1];
                }
            }
        }

        return dp[0];
    }
};