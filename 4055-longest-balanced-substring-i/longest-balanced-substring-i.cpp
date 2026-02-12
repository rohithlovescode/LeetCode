class Solution {
public:
    int longestBalanced(string s) {
        int ans=0;
        vector<int> counts(26,0);
        map<int,int> countOfCounts;
        
        
        int numUnique=0;
        int leng=s.length();

        for(int i=0;i<leng;i++){
            for(int j=i;j<leng;j++){
                char c=s[j];
                if(counts[c-'a']==0){
                    numUnique++;
                }
                
                counts[c-'a']++;
                int temp=counts[c-'a'];
                countOfCounts[temp]++;
                countOfCounts[temp-1]--;
                if(countOfCounts[temp]==numUnique){
                    ans=max(ans,j-i+1);
                }
                
            }
            for(int i=0;i<26;i++){
                counts[i]=0;
            }
            numUnique=0;
            countOfCounts.clear();
        }
        return ans;
    }
};