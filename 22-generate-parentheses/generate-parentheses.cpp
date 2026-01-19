class Solution {
public:
    void generate(int n,string& curr, int offset,vector<string>& ans){
        if(n==0&&offset==0){
            ans.push_back(curr);
        }

        if(n>0){
            curr+='(';
            generate(n-1,curr,offset+1,ans);
            curr.pop_back();
        }
        if(offset>0){
            curr+=')';
            generate(n,curr,offset-1,ans);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        int offset=0;//determines (openBrackets-closedBrackets)

        string curr="";

        generate(n,curr,offset,ans);

        return ans;


    }
};