class Solution {
public:
    int modifiedBinarySearch(vector<int>& position,int left,int right,int& m){
        // base condition
        if(left>right){
            return -1;
        }

        int n=position.size();
        //size of position
        int remainingBalls=m;

        int mid=left+(right-left)/2;
        // not going out of bounds

        int prevBall=position[0];//putting in first position
        remainingBalls--;

        for(int i=1;i<n;i++){
            if((position[i]-prevBall)>=mid){
                prevBall= position[i];
                remainingBalls--;
            }
            if(remainingBalls==0){
                break;
            }
        }

        if(remainingBalls==0){
            int rightBS=modifiedBinarySearch(position,mid+1,right,m);
            return max(rightBS,mid);
        }

        int leftBS=modifiedBinarySearch(position,left,mid-1,m);
        return leftBS;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        //sort the array;
        int n=position.size();//size of the array

        int left=1;
        int right=position[n-1];
        // represent left and right values for binary search


        
        return modifiedBinarySearch(position,left,right,m);


    }
};