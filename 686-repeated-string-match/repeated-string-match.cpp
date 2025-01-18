class Solution {
public:
    int solve(string a, string b,int multiplier){
        string newStr="";
        for(int i=0;i<multiplier;i++){
            newStr+=a;
        }
        int ind=newStr.find(b);
        if(ind<newStr.size()){
            return multiplier;
        }
        return INT_MAX;
    }
    int repeatedStringMatch(string a, string b) {
        int leng1=a.length();
        int leng2=b.length();
        
        int multiplier=ceil(float(leng2)/leng1);
        int ans;
        ans=min(solve(a,b,multiplier),solve(a,b,multiplier+1));
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};