class Solution {
    vector<int> findPrev(vector<int> heights){
        stack<int> stack;
        vector<int> sol(heights.size());

        stack.push(-1);
        for(int i=0;i<heights.size();i++){
            // todo -1 case
            while(stack.top()!=-1&& heights[stack.top()]>=heights[i]){
                stack.pop();
            }
            sol[i]=stack.top();
            stack.push(i);
            
        }
        return sol;
    }


    vector<int> findNext(vector<int> heights){
        stack<int> stack;
        vector<int> sol(heights.size());

        stack.push(-1);
        for(int i=heights.size()-1;i>=0;i--){
            while(stack.top()!=-1&&heights[stack.top()]>=heights[i]){
                stack.pop();
            }
            sol[i]=stack.top();
            stack.push(i);
        }
        return sol;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> prev(n);
        prev=findPrev(heights);
        // the prev represents the index of first left least element
        vector<int> next(n);
        next=findNext(heights);
        // the next represent the index of first right least element, -1 if not posble
        int maxArea=0;
        for(int i=0;i<n;i++){
            int l=heights[i];
            if(next[i]==-1)
                next[i]=n;
            int b=next[i]-prev[i]-1;

            int area=l*b;
            if(area>maxArea)
                maxArea=area;
        }
        return maxArea;
    }
};