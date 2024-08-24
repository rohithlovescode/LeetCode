class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> s;
        int n=temperatures.size();
        vector<int> ans(n);
        ans[n-1]=0;
        s.push({temperatures[n-1],n-1});
        for(int i=n-2;i>=0;i--){
            while(!s.empty()&&s.top().first<=temperatures[i]){
                s.pop();
            }
            if(s.empty()){
                ans[i]=0;
            }else{
                ans[i]=s.top().second-i;
            }
            s.push({temperatures[i],i});
        }
        return ans;
    }
};