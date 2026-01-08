class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> passengers(1001,0);

        for(auto trip: trips){
            int numPassengers=trip[0];
            int from=trip[1];
            int to=trip[2];
            passengers[from]+=numPassengers;
            passengers[to]-=numPassengers;
        }
        int total=0;

        for(int i=0;i<=1000;i++){
            total+=passengers[i];
            if(total>capacity) return false;
        }

        return true;

    }
};