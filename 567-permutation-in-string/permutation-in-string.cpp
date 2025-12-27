class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freqs1(26,0);
        vector<int> freqs2(26,0);
        int numMatching=26;
        if(s1.size()>s2.size()) return false;


        for(int i=0;i<s1.size();i++){
            if(freqs1[s1[i]-'a']==freqs2[s1[i]-'a']){
                numMatching--;
            }
            freqs1[s1[i]-'a']++;
        }
        
        for(int i=0;i<s1.size();i++){
            if(freqs1[s2[i]-'a']==freqs2[s2[i]-'a']){
                numMatching--;
            }
            freqs2[s2[i]-'a']++;
            if(freqs1[s2[i]-'a']==freqs2[s2[i]-'a']){
                numMatching++;
            }
        }
        for(int i=s1.size();i<s2.size();i++){
            if(numMatching==26) return true;

            int delInd=i-s1.size();
            if(freqs1[s2[delInd]-'a']==freqs2[s2[delInd]-'a']){
                numMatching--;
            }
            freqs2[s2[delInd]-'a']--;
            if(freqs1[s2[delInd]-'a']==freqs2[s2[delInd]-'a']){
                numMatching++;
            }

            
            if(freqs1[s2[i]-'a']==freqs2[s2[i]-'a']){
                numMatching--;
            }
            freqs2[s2[i]-'a']++;
            if(freqs1[s2[i]-'a']==freqs2[s2[i]-'a']){
                numMatching++;
            }


        }
        return numMatching==26;

    }
};