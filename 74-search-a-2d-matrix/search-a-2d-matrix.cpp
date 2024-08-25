class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int s=0;
        int e=m-1;
        int mid;
        int reqRow=-1;
        while(s<=e){
            mid=s+(e-s)/2;
            if(matrix[mid][0]==target){
                return true;
            }else if(matrix[mid][0]<target){
                reqRow=mid;
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        if(reqRow==-1) return false;
        s=0;
        e=n-1;
        while(s<=e){
            mid=s+(e-s)/2;
            if(matrix[reqRow][mid]==target){
                return true;
            }
            else if(matrix[reqRow][mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return false;
        
    }
};