class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int lmax=height[0];
        int rmax=height[n-1];
        int lpos=1;
        int rpos=n-2;
        int water=0;
        while(lpos<=rpos){
            if(height[lpos]>=lmax){
                lmax=height[lpos];
                lpos++;
            }
            else if(height[rpos]>=rmax){
                rmax=height[rpos];
                rpos--;
            }
            else if(lmax<rmax){
                water+=(lmax-height[lpos]);
                lpos++;
            }
            else{
                water+=(rmax-height[rpos]);
                rpos--;
            }
        }
        return water;
    }
};
/*class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int highest,highestIndex;
        int sol=0;
        if(n<3)
        return 0;
        if(height[0]>height[1]){
            highest=height[0];
            highestIndex=0;
        }
        else{
            highest=height[1];
            highestIndex=1;
        }
        for(int i=2;i<n;i++){
            if(highest!=0&&height[i]>0){
                int temp=0;
                for(int j=i-1;j>highestIndex;j--){
                    temp=max(temp,height[j]);
                    if(height[j]>=height[i]){
                        break;
                    }
                    sol=sol+(min(height[i],highest)-temp);
                }
            }
            if(height[i]>highest){
                highest=height[i];
                highestIndex=i;
            }
        }
        return sol;
    }
};*/