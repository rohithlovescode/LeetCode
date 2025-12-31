class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(auto stone: stones){
            pq.push(stone);
        }
        while(pq.size()>1){
            int maxi1=pq.top();pq.pop();
            int maxi2=pq.top();pq.pop();
            if(maxi1-maxi2>0){
                pq.push(maxi1-maxi2);
            }
        }

        if(pq.empty()) return 0;
        return pq.top();
    }
};