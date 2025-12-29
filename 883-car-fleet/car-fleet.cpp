class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> vec;
        int n=position.size();
        for(int i=0;i<n;i++){
            vec.push_back({position[i],speed[i]});
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<n;i++){
            position[i]=vec[i].first;
            speed[i]=vec[i].second;
        }

        int ans=0;
        double nextCarTime=0;

        for(int i=n-1;i>=0;i--){
            double currTime=(double)(target-position[i])/speed[i];
            if(currTime>nextCarTime){
                ans++;
                nextCarTime=currTime;
            }
        }
        return ans;
        
    }
};