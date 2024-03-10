class MedianFinder {
    int size;
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
public:
    MedianFinder() {
        size=0;
    }
    
    void addNum(int num) {
        if(size==0){
            left.push(num);
        }
        else{
            if(size%2==1){
                if(left.top()<=num){
                    right.push(num);
                }else{
                    int topp=left.top();
                    left.pop();
                    left.push(num);
                    right.push(topp);
                }
            }else{
                if(right.top()<num){
                    int topp=right.top();
                    right.pop();
                    right.push(num);
                    left.push(topp);
                }
                else{
                    left.push(num);
                }
            }
        }
        size++;
    }
    
    double findMedian() {
        if(size==0){
            return -1;
        }else if(size%2==1){
            return left.top();
        }

        else if(size%2==0){
            int leftVal=left.top();
            int rightVal=right.top();
            double ans=double(double(leftVal)+double(rightVal))/2;
            return ans;
        }
        return 0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */