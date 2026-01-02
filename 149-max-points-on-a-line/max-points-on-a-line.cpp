class Solution {
public:
    int binarySearch(int left, int right, int ans){
        if(left>right) return left;
        int mid= left+(right-left)/2;
        int temp=mid*(mid+1)/2;
        if(temp==ans) return mid;
        else if(temp<ans) return binarySearch(mid+1,right,ans);
        else return binarySearch(left,mid-1,ans);
    }
    int maxPoints(vector<vector<int>>& points) {
        map<double,int> freq;
        int n=points.size();
        int ans=0;
        map<int,int> straightLineFreq;

        for(int i=0;i<n;i++){
            int x1=points[i][0],y1=points[i][1];
            for(int j=i+1;j<n;j++){
                
                int y2=points[j][1],x2=points[j][0];
                if(x2==x1){
                    straightLineFreq[x1]++;
                    ans=max(ans,straightLineFreq[x1]);
                    continue;
                }
                double slope= double(y2-y1)/double(x2-x1);

                freq[slope]++;
                cout<<slope<<" "<<freq[slope]<<endl;
                ans=max(ans,freq[slope]);
            }
            freq.clear();
            straightLineFreq.clear();
        }
        
        return ans+1;
    }
};