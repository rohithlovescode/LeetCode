class Solution {
public:
    string largestEven(string s) {
        string ans="";
        int lastEvenInd=-1;

        for(int i=s.length()-1;i>=0;i--){
            if((s[i]-'0')%2==0){
                lastEvenInd=i;
                break;
            }
        }
        if(lastEvenInd==-1) return ans;

        return s.substr(0,lastEvenInd+1);
    }
};