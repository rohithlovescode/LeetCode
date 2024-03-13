class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minLen=INT_MAX;
        int n=strs.size();
        if(n==0){
            return "";
        }
        if(n==1){
            return strs[0];
        }
        for(int i=0;i<n;i++){
            if(strs[i].size()<minLen){
                minLen=strs[i].size();
            }
        }
        string ans="";
        for(int i=0;i<minLen;i++){
            char temp=strs[0][i];
            for(int j=1;j<n;j++){
                if(strs[j][i]!=temp){
                    return ans;
                }
                if(j==n-1){
                    ans+=temp;
                }
            }
        }
        return ans;
    }
};