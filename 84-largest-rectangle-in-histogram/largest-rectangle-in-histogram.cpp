class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(-1);
        int ans=0;

        for(int i=0;i<heights.size();i++){
            int top=st.top();
            if(top==-1||heights[top]<heights[i]){
                st.push(i);
            }else{
                // [5 5 5 5]
                //  > -1 
                while(st.top()!=-1&&heights[st.top()]>=heights[i]){
                    int temp=st.top();
                    st.pop();
                    ans=max(ans,(i-st.top()-1)*heights[temp]);
                }
                st.push(i);
            }
        }
        
                while(st.top()!=-1){
                    int temp=st.top();
                    int size=heights.size();
                    st.pop();
                    ans=max(ans,(size-st.top()-1)*heights[temp]);
                }
                return ans;
    }
};