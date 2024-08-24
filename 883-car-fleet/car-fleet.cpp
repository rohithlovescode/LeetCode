class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<float> time;
        int n=position.size();
        for(int i=0;i<n;i++){
            time.push_back(float(target-position[i])/float(speed[i]));
        }
        priority_queue<pair<int,float>> cars;
        for(int i=0;i<n;i++){
            cars.push({position[i],time[i]});
        }
        int ans=1;
        pair<int,float> prev=cars.top(),top;
        cars.pop();
        for(int i=1;i<n;i++){
            top=cars.top();
            cars.pop();
            if(prev.second<top.second){
                ans++;
                
            }else{
                top.second=prev.second;
            }
            prev=top;
        }
        return ans;
    }
};