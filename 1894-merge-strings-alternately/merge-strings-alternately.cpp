class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string sol="";
        int i=0,j=0;
        int m=word1.length(),n=word2.length();
        while(i<m || j<n){
            if(i<m){
                sol+=word1[i];
                i++;
            }
            if(j<n){
                sol+=word2[j];
                j++;
            }
        }
        return sol;
    }
};