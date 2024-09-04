class Solution {
public:
    bool checkMappings(map<char,int> reqCounts,map<char,int> currCounts){
        for(auto it:reqCounts){
            if(currCounts[it.first]!=it.second){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        map<char,int> reqCounts;
        map<char,int> currCounts;
        int leng1=s1.length();
        int leng2=s2.length();
        if(leng1>leng2){
            return false;
        }

        for(char it: s1){
            reqCounts[it]++;
        }
        for(int i=0;i<leng1;i++){
            currCounts[s2[i]]++;
        }
        
        if(checkMappings(reqCounts,currCounts)){
            return true;
        }
        for(int i=leng1;i<leng2;i++){
            currCounts[s2[i-leng1]]--;
            currCounts[s2[i]]++;
            if(checkMappings(reqCounts,currCounts)){
                return true;
            }
        }

        return false;
    }
};