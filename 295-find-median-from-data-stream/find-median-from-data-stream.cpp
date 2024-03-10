class MedianFinder {
    vector<int> arr;
public:
    MedianFinder() {
        
    }
    void insertionSort(){
        int last=arr[arr.size()-1];
        int i;
        for(i=0;i<arr.size()-1;){
            if(arr[i]<last){
                i++;
            }
            else{
                break;
            }
        }
        for(int j=arr.size()-1;j>i;j--){
            arr[j]=arr[j-1];
        }
        arr[i]=last;
    }
    
    void addNum(int num) {
        arr.push_back(num);
        if(arr.size()>1)
            insertionSort();
    }
    
    double findMedian() {
        int n=arr.size();
        if(n==0){
            return -1;
        }
        if(n%2==1){
            return arr[n/2];
        }else{
            float ans=float(arr[n/2]+arr[n/2-1])/2;
            return ans;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */