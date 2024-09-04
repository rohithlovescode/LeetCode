class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> v={0};
        int tmp=1;
        for(int i=1;i<=n;i++){
            v.push_back(i);
            tmp*=i;
        }
        string s;
        cout<<tmp<<" ";
        for(int i=n;i>=2;i--){
            tmp/=i;
            int fl=(k+tmp-1)/tmp;
            s.push_back(v[fl]+'0');
            k-=(fl-1)*tmp;
            for(int j=fl;j<v.size()-1;j++){
                v[j]=v[j+1];
            }
        }
        s.push_back(v[1]+'0');   
        return s;
    }
};

