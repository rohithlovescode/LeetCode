class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int i=0;i<nums.size();i++){
            if(pq.size()<k) pq.push(nums[i]);
            
            else if(pq.size()==k&&pq.top()<=nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if(pq.size()<k) pq.push(val);
            
        else if(pq.size()==k&&pq.top()<=val){
            pq.pop();
            pq.push(val);
        }
        return pq.size()==k?pq.top():-1;
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */