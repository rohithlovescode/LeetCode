class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> count;
        for(int i=0;i<arr.size();i++){
            count[arr[i]]++;
        }
        vector<int> freq;
        for(auto i:count ){
            freq.push_back(i.second);
        }
        sort(freq.begin(),freq.end());
        for(int i=0;i<freq.size();i++){
            k=k-freq[i];
            if(k==0){
                return freq.size()-i-1;
            }
            if(k<0){
                return freq.size()-i;
            }
        }
        return 0;

    }
};