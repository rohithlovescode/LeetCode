class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> counts1(26,0);
        vector<int> counts2(26,0);

        for(auto ch:s){
            counts1[ch-'a']++;
        }
        for(auto ch:t){
            counts2[ch-'a']++;
        }

        for(int i=0;i<counts1.size();i++){
            if(counts1[i]!=counts2[i]){
                return false;
            }
        }
        return true;
    }
};