class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);

        vector<vector<int>> adjList(numCourses,vector<int>());//syntax

        for(vector<int> prereq:prerequisites){//syn
            int i=prereq[0];
            int j=prereq[1];
            adjList[i].push_back(j);
            indegree[j]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        
        int coursesComplete=0;

        while(!q.empty()){
            int front=q.front();
            q.pop();
            coursesComplete++;
            for(auto neigh:adjList[front]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
                
            }
        }
        return coursesComplete==numCourses;
    }
};