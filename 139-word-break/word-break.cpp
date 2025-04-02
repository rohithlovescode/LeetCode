class Solution {
public:
    bool recurse(string s, int ind, vector<string>& wordDict,vector<int>& dp){
        if(ind==s.length()){
            return true;
        }
        if(dp[ind]!=-1){
            return dp[ind]==1?true:false;
        }
        bool currAns=false;

        for(string word:wordDict){
            if(!currAns && s.find(word,ind)==ind){
                currAns=recurse(s,ind+word.length(),wordDict,dp);
            }
        }
        dp[ind]= currAns==true?1:0;
        return currAns;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int ind=0;
        vector<int> dp(s.length(),-1);
        return recurse(s,ind,wordDict,dp);
    }
};