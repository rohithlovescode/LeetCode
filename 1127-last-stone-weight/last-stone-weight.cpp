class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto stone: stones){
            pq.push(stone);
        }
        while(pq.size()>1){
            int top1=pq.top();
            pq.pop();
            int top2=pq.top();
            pq.pop();
            if(top1==top2){
                continue;
            }else{
                top1=top1-top2;
                pq.push(top1);
            }
        }
        if(pq.empty()){
            return 0;
        }
        return pq.top();
    }
};