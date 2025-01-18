class Solution {
public:
    int nextVal(int& ind,string& version){
        int ans=0;
        while(ind<version.length()&&version[ind]!='.'){
            ans=ans*10+(version[ind]-'0');
            ind++;
        }
        ind++;
        return ans;
    }
    int compareVersion(string version1, string version2) {
        int i=0,j=0;
        while(i<version1.length()||j<version2.length()){
            int v1=nextVal(i,version1);
            int v2=nextVal(j,version2);
            if(v1<v2){
                return -1;
            }else if(v1>v2){
                return 1;
            }
        }
        return 0;
    }
};