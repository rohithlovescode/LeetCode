class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adjList(numCourses);

        // Build graph with correct edge direction
        for (const vector<int>& prereq : prerequisites) {
            int course = prereq[0];
            int pre = prereq[1];
            adjList[pre].push_back(course); // pre -> course
            indegree[course]++;             // increment course's indegree
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }

        int coursesComplete = 0;

        while(!q.empty()){
            int front = q.front();
            q.pop();
            coursesComplete++;

            for(auto neigh : adjList[front]){
                indegree[neigh]--;
                if(indegree[neigh] == 0){
                    q.push(neigh);
                }
            }
        }

        return coursesComplete == numCourses;
    }
};
