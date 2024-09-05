class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> reqCounts;
        int uniqueChar=0;
        for(char ch:t){
            if(reqCounts[ch]==0){
                uniqueChar++;
            }
            reqCounts[ch]++;
        }
        map<char,int> currCounts;
        currCounts[s[0]]++;
        int matching=0;
        if((currCounts[s[0]]==reqCounts[s[0]])&&reqCounts[s[0]]!=0){
            matching++;
        }
        int left=0;
        int right=0;
        int minChar=INT_MAX;
        string ans="";
        while(right<s.length()){
            if(matching==uniqueChar){
                if((right-left+1)<minChar){
                    minChar=right-left+1;
                    ans=s.substr(left,right-left+1);
                }
                if(currCounts[s[left]]==reqCounts[s[left]]){
                    matching--;
                }
                currCounts[s[left]]--;
                left++;
            }else{
                right++;
                currCounts[s[right]]++;
                if(currCounts[s[right]]==reqCounts[s[right]]){
                    matching++;
                }
                if(currCounts[s[left]]>reqCounts[s[left]]){
                    currCounts[s[left]]--;
                    left++;
                }
            }
        }
        return ans;



    }
};