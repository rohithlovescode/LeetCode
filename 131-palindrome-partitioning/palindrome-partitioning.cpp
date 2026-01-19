class Solution {
public:
    bool isPalindrome(string str){
        int leng=str.length();
        for(int i=0;i<leng/2;i++){
            if(str[i]!=str[leng-i-1]) return false;
        }

        return true;
    }
    void recurse(int ind, vector<vector<string>>& ans,vector<string> &partitioning,string &s){
        if(ind>=s.length()) {
            ans.push_back(partitioning);
            return;
        }
        string str="";

        for(int i=ind;i<s.length();i++){
            str+=s[i];
            if(isPalindrome(str)) {
                partitioning.push_back(str);
                recurse(i+1,ans,partitioning,s);
                partitioning.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitioning;

        recurse(0,ans,partitioning,s);
        return ans;

    }
};