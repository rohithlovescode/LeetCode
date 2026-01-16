class Solution {
public:
    long long countPairs(vector<string>& words) {
        long long ans=0;
        map<string,int> counts;

        for(int i=0;i<words.size();i++){
            string word=words[i];
            int diff=word[0]-'a';
            cout<<diff<<endl;
            for(int j=0;j<word.length();j++){
                if (word[j] - diff < 'a') {
    word[j] = word[j] + 26 - diff;
} else {
    word[j] = word[j] - diff;
}
            }
            words[i]=word;
            counts[word]++;
        }
        for(auto [str,cnt]:counts){
            if(cnt>1){
                ans += 1LL * cnt * (cnt - 1) / 2;
            }
        }

        return ans;
    }
};