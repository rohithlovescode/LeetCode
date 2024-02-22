class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> people(n,0);
        vector<int> knows(n,0);

        for(int i=0;i<trust.size();i++){
            people[trust[i][1]-1]++;
            knows[trust[i][0]-1]++;
        }
        for(int i=0;i<people.size();i++){
            if(people[i]==n-1&&knows[i]==0){
                return i+1;
            }
        }
        return -1;
    }
};