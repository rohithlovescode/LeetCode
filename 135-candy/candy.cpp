class Compare{
    public:
    bool operator()(const pair<int,int>& a,const pair<int,int>& b){
        return a.first>b.first;
    }
};
class Solution {
public:
    int candy(vector<int>& ratings) {
        priority_queue<pair<int,int>, vector<pair<int,int>>,Compare> pq;
        int n=ratings.size();
        int ans=0;

        vector<int> candies(ratings.size(),0);
        for(int i=0;i<n;i++){
            pq.push({ratings[i],i});
        }
        while(!pq.empty()){
            auto [val,ind]=pq.top(); pq.pop();
            int minCandies=1;
            if(ind>0){
                if(ratings[ind-1]!=ratings[ind]){
                    minCandies=max(minCandies,candies[ind-1]+1);
                }
            }
            if(ind<n-1){
                if(ratings[ind+1]!=ratings[ind]){
                    minCandies=max(minCandies,candies[ind+1]+1);
                }
            }
            ans+=minCandies;
            candies[ind]=minCandies;

        }

        return ans;

    }
};