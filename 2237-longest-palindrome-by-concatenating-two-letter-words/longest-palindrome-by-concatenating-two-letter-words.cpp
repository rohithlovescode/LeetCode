class Solution {
public:
    string rev(string str){
        int l=str.length();
        for(int i=0;i<l/2;i++){
            swap(str[i],str[l-i-1]);
        }
        return str;
    }
    
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> freq;
        int ans=0;
        for(auto word: words){
            string revv=rev(word);
            if(freq.count(revv)==0){
                freq[word]++;
            }else{
                freq[revv]--;
                ans+=4;
                if(freq[revv]==0) freq.erase(revv);
            }
        }
        for(auto k: freq){
            if(rev(k.first)==k.first){
                ans+=2;
                break;
            }
        }
        return ans;
    }
};