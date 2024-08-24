class MinStack {
    vector<int> myStack;
    vector<int> minimumElement;
    int topIndex;
public:
    MinStack() {
        topIndex=-1;
    }
    
    void push(int val) {
        topIndex++;
        if(myStack.size()<=topIndex){
            myStack.push_back(val);
            if(topIndex==0){
                minimumElement.push_back(val);
            }
            else{
                minimumElement.push_back(min(val,minimumElement[topIndex-1]));
            }
        }
        else{
            myStack[topIndex]=(val);
            if(topIndex==0){
                minimumElement[topIndex]=(val);
            }
            else{
                minimumElement[topIndex]=min(val,minimumElement[topIndex-1]);
            }
            
        }

    }
    
    void pop() {
        if(topIndex!=-1){
            topIndex--;
        }
    }
    
    int top() {
        if(topIndex!=-1)
            return myStack[topIndex];
        else
            return -1;
    }
    
    int getMin() {
        if(topIndex!=-1)
            return minimumElement[topIndex];
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */