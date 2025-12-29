class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(-1);
        int n=heights.size();
        int ans=0;

        for(int i=0;i<heights.size();i++){
            while(st.top()!=-1&&heights[st.top()]>=heights[i]){
                int topInd=st.top();
                st.pop();
                ans=max(ans,heights[topInd]*(i-st.top()-1));
            }
            st.push(i);
        }

        while(st.top()!=-1){
            int topInd=st.top();
            st.pop();
            ans=max(ans,heights[topInd]*(n-st.top()-1));

        }
        return ans;
    }
};