class Solution {
public:
    bool solve(int pos,int k,const int& finalpos,map<int,int>& indexMap,map<pair<int,int>,int>& dp){
        if(pos==finalpos){
            return true;
        }
        if(dp[{k,pos}]!=0){
            if( dp[{k,pos}]==1){
                return true;
            }
            return false;
        }
        bool solvable=false;
        if(k>1&&indexMap[pos+k-1]!=0){
            solvable=solvable||solve(pos+k-1,k-1,finalpos,indexMap,dp);
        }
        if(indexMap[pos+k]!=0){
            solvable=solvable||solve(pos+k,k,finalpos,indexMap,dp);
        }
        if(indexMap[pos+k+1]!=0){
            solvable=solvable||solve(pos+k+1,k+1,finalpos,indexMap,dp);
        }
        dp[{k,pos}]=solvable?1:-1;
        return solvable;
    }
    bool canCross(vector<int>& stones) {
        map<pair<int,int>,int> dp;//k val and ind, -1 means false, and 1 means true,0 means unvisited obv
        map<int,int> indexMap;
        int n=stones.size();
        for(int i=0;i<n;i++){
            indexMap[stones[i]]=i;
        }
        if(indexMap[stones[0]+1]==0){
            return false;
        }
        int start=stones[0]+1;
        int k=1;

        return solve(start,k,stones[n-1],indexMap,dp);
    }
};