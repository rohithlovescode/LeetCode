class Solution {
public:
    char findMostRepeated(const map<char,int> &counts){
        char mostRepeated='A';
        int val=0;
        for(auto count: counts){
            if(count.second>val){
                mostRepeated=count.first;
                val=count.second;
            }
        }
        return mostRepeated;
    }
    int characterReplacement(string s, int k) {
        int left=0,right=0;
        int ans=1;
        int leng=s.length();
        char mostRepeated='A';

        map<char,int> mapp;
        map<int,bool> visited;
        while(right<leng){
            char currChar=s[right];
            if(!visited[right]){
                mapp[currChar]=mapp[currChar]+1;
                visited[right]=true;
            }
            if(mapp[currChar]>mapp[mostRepeated]){
                mostRepeated=currChar;
            }
            int temp=right-left+1-mapp[mostRepeated];
            if(temp<=k){
                ans=max(right-left+1,ans);
                right++;
            }else{
                mapp[s[left]]--;
                left++;
                mostRepeated=findMostRepeated(mapp);
            }
        }
        return ans;
    }
};