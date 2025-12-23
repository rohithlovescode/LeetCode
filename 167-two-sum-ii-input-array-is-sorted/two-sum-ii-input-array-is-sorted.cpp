class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0,right=numbers.size()-1;

        while(left<right){
            if(target==(numbers[left]+numbers[right])){
                return vector({left+1,right+1});
            }else if(target>(numbers[left]+numbers[right])){
                left++;
            }else{
                right--;
            }

        }
        return {};
    }
};