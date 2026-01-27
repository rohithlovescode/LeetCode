class Solution {
public:
    void helper(string& s,int left,int right,int &leng, int &sInd,vector<vector<int>>& dp)// here s is gonna be copied everytime?
    {
        if(left==right) {
            dp[left][right]=1;
            if(leng==0){
                leng=1;
                sInd=left;
            }
            return;
        }
        if(left==right-1){
            dp[left][right]=(s[left]==s[right])?1:-1;//
            
            if(dp[left][right]==1&&leng<2){
                leng=2;
                sInd=left;
            }else{
            helper(s,left+1,right,leng,sInd,dp);
            helper(s,left,right-1,leng,sInd,dp);

            }
            return;
        }
        if(dp[left][right]!=0) return;
        helper(s,left+1,right-1,leng,sInd,dp);
        
        if(dp[left+1][right-1]==1&&s[left]==s[right]) {
            
            dp[left][right]=1;
            if((right-left+1)>leng){
                sInd=left;
                leng=right-left+1;
            }
        }else{
            dp[left][right]=-1;
            helper(s,left+1,right,leng,sInd,dp);
            helper(s,left,right-1,leng,sInd,dp);
        }
    }
    string longestPalindrome(string s) {
        int leng=s.length();
        int left=0, right=leng-1;

        vector<vector<int>> dp(leng,vector<int>(leng,0));
        int startInd=0;
        int maxLeng=0;// does returning value have any thing

        helper(s,left,right,maxLeng,startInd,dp);
        return s.substr(startInd,maxLeng);
        
    }
};