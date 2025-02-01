class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int> freeTimes;
        int tempSum=0;
        
        freeTimes.push_back(startTime[0]);
        for(int i=0;i<n;i++){
            if(i==n-1){
                freeTimes.push_back(eventTime-endTime[i]);
                continue;
            }
            freeTimes.push_back(startTime[i+1]-endTime[i]);
        }
        
        //k is window size
        int spaceSize=freeTimes.size();
        for(int i=0;i<=k&&i<spaceSize;i++){
            tempSum+=freeTimes[i];
        }
        int ans=tempSum;
        for(int i=k+1;i<spaceSize;i++){
            tempSum-=freeTimes[i-k-1];
            tempSum+=freeTimes[i];
            ans=max(ans,tempSum);
        }

        return ans;
        
    }
};