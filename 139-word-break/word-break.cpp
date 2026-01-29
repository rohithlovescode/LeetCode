class Solution {
public:
    bool recurse(const string &s,int ind,unordered_map<string,bool>& wordMap,vector<int>& dp){
        if(ind==s.length()) return true;
        if(dp[ind]!=0){
            return dp[ind]==1?true:false;
        }

        string currStr="";
        for(int i=ind;i<s.length();i++){
            currStr+=s[i];
            if(wordMap.count(currStr)!=0){
                if(dp[i+1]==0) recurse(s,i+1,wordMap,dp);

                if(dp[i+1]==1){
                    dp[ind]=1;
                    return true;
                }
            }
        }
        dp[ind]=-1;
        return false;
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.length()+1,0);
        dp[s.length()]=1;
        unordered_map<string,bool> wordMap;
        for(auto word:wordDict){
            wordMap[word]=true;
        }

        return recurse(s,0,wordMap,dp);
    }
};