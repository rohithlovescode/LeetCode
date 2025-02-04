class Solution {
public:
    int find(vector<int>& parent,int ind){
        while(parent[ind]!=ind){
            ind=parent[ind];
        }
        return ind;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int numProvince=n;
        vector<int> parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j]==0){
                    continue;
                }
                int a=find(parent,i);
                int b=find(parent,j);
                if(a!=b){
                    parent[a]=b;
                    numProvince--;
                }
            }
        }
        return numProvince;
    }
};