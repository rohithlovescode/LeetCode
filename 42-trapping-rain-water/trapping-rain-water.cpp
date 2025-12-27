class Solution {
public:
    int trap(vector<int>& height) {
        // leftMax, rightMax
        // left,right 
        
        int leftMax=0,rightMax=0;
        int left=0,right=height.size()-1;
        int ans=0;

        while(left<right){
            if(height[left]<=height[right]){
                leftMax=max(leftMax,height[left]);
                left++;
                if(height[left]<leftMax){
                    ans+=(leftMax-height[left]);
                }
            }else{
                rightMax=max(rightMax,height[right]);
                right--;
                if(height[right]<rightMax){
                    ans+=(rightMax-height[right]);
                }
            }
        }
        return ans;
    }
};