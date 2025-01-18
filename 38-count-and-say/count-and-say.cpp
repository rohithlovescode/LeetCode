class Solution {
public:
    string RLE(string s){
        int leng=s.length();
        if(leng==0){
            return s;
        }
        char currChar=s[0];
        int temp=1;
        int i;
        string ans="";
        for(int i=1;i<leng;i++){
            if(s[i]==currChar){
                temp++;
            }
            else{
                ans+=('0'+temp);
                ans+=currChar;
                temp=1;
                currChar=s[i];
            }
        }
        ans+=('0'+temp);
        ans+=currChar;
        return ans;

    }

    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        return RLE(countAndSay(n-1));
    }
};