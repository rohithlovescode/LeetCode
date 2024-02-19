class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> ace=heights;
        int count =0;
        sort(ace.begin(),ace.end());
        for(int i=0;i<ace.size();i++){
            if(ace[i]!=heights[i]){
                count++;
            }
        }
        return count;
    }
};