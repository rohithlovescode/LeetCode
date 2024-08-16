class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int numsLength = nums.size();
        // initialize the cursor
        int i = 0;

        // phase 1: sort the numbers with cyclic sort
        // move the cursor through the list
        while (i < numsLength) {
            // has minus 1 because the numbers start from 1 not 0
            long valAtI = (long)nums[i] - 1;

            // does the value belong in the range of the list?
            // if it doesn't, we get an out of bounds error
            // when we try to access nums[valAtI] later
            bool belongsInRange = valAtI >= 0 && valAtI < numsLength;

            if (belongsInRange && nums[i] != nums[valAtI]) {
                swap(nums[i], nums[valAtI]);
            } else {
                i++;
            }
        }

        // phase 2: find the first missing positive integer
        for (int x = 0; x < numsLength; x++) {
            // has plus 1 because the numbers start from 1 not 0
            if (x + 1 != nums[x]) {
                return x + 1;
            }
        }

        // if all numbers are in the correct spot,
        // the first missing positive integer is the
        // length of the list + 1
        return numsLength + 1;
    }
};