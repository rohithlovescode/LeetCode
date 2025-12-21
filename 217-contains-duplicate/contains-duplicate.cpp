class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,bool> mapp;

        for(auto num: nums){
            if(mapp.count(num)!=0){
                return true;
            }
            mapp[num]=true;
        }

        return false;
    }
};