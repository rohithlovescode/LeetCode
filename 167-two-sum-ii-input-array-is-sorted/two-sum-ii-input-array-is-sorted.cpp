class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0;
        int right=numbers.size()-1;
        vector<int> sol;
        while(left<right){
            int currSum=numbers[left]+numbers[right];
            if(currSum==target){
                sol.push_back(left+1);
                sol.push_back(right+1);
                return sol;
            }
            else if(currSum>target){
                right--;
            }else{
                left++;
            }
        }
        return sol;
    }
};