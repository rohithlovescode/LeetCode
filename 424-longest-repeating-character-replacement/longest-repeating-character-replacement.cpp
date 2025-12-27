class Solution {
public:
    int calculateMaxSubstring(char ch,string s,int k){
        int maxLength=0;
        int left=0,right=0;
        int changesLeft=k;

        //"BBBBBAAAAABBBAAAA",k=5 changes
        //  .........|
        // cl=0
        while(right<s.size()){
            if(ch==s[right]){
                right++;
            }else{
                changesLeft--;
                    right++;
                while(changesLeft<0){
                    if(ch!=s[left]){
                        changesLeft++;
                    }
                    left++;
                }
                
            }
            maxLength=max(maxLength,right-left);
        }
        return maxLength;
        
    }
    int characterReplacement(string s, int k) {
        int ans=0;
        
        for(char ch='A';ch<='Z';ch++){
            int maxSubstring=calculateMaxSubstring(ch,s,k);
            ans=max(ans,maxSubstring);
        }

        return ans;
    }
};
