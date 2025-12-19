class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjList(n,vector<int>());

        for(auto edge:edges){
            int node1=edge[0];
            int node2=edge[1];

            adjList[node1].push_back(node2);
            adjList[node2].push_back(node1);


        }

        vector<bool> visited(n,false);

        stack<int> st;
        st.push(source);
        visited[source]=true;

        while(!st.empty()){
            int top=st.top();
            st.pop();
            if(top==destination) return true;
            for(auto neigh:adjList[top]){
                if(!visited[neigh]){
                    st.push(neigh);
                    visited[neigh]=true;
                }
            }
        }

        return false;
    }
};