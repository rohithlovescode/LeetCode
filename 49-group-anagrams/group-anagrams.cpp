class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> mapp;
        vector<vector<string>> ans;
        for(auto s: strs){
            vector<int> counts(26,0);
            for(char c: s){
                counts[c-'a']++;
            }

            string key="";
            for(auto c:counts){
                key+="#";
                key+= to_string(c);
            }
            mapp[key].push_back(s);
        }
        
        for(auto pair:mapp){
            ans.push_back(pair.second);
        }

        return ans;

    }
};