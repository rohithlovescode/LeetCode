class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        queue<pair<int,int>> month;
        queue<pair<int,int>> week;
        int ans=0;

        for(int day: days){
            while(!month.empty()&&month.front().first+30<=day){
                month.pop();
            }
            while(!week.empty()&&week.front().first+7<=day){
                week.pop();
            }

            week.push(make_pair(day,ans+costs[1]));
            month.push(make_pair(day,ans+costs[2]));

            ans=min(ans+costs[0],min(month.front().second,week.front().second));
        }
        return ans;
    }
};