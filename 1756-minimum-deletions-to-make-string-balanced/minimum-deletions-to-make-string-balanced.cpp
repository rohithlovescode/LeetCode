class Solution {
public:
    int minimumDeletions(string s) {
        int partInd=s.length();
        int temp=0;

        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(ch=='b'){
                if(temp==0) partInd=i;

                temp++;
            }
            else if(temp==0){
                continue;
            }else{
                temp--;
                if(temp==0) partInd=s.length();
            }
        }
        int ans=0;
        for(int i=0;i<partInd;i++){
            if(s[i]=='b') ans++;
        }
        for(int i=partInd;i<s.length();i++){
            if(s[i]=='a') ans++;
        }
        return ans;
    }
};