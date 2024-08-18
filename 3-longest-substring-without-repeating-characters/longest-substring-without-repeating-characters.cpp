class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int leng=s.length();
        if(leng<=1){
            return leng;
        }

        int left=0;
        int right=1;
        int sol=1;
        int curr=1;
        while(right<leng){
            if(s.find(s[right],left)==right){
                curr++;
                right++;
                sol=max(sol,curr);
            }
            else{
                left++;
                curr--;
            }
        }
        return sol;

    }
};