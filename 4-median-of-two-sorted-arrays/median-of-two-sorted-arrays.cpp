class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        
        if (len1 > len2)
            return findMedianSortedArrays(nums2, nums1);
        
        int totalLength = len1 + len2;
        int partitionSize = (len1 + len2 + 1) / 2;
        int low = 0, high = len1;
        
        while (low <= high) {
            int partition1 = (low + high) >> 1;
            int partition2 = partitionSize - partition1;
            
            int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int minRight1 = (partition1 == len1) ? INT_MAX : nums1[partition1];
            
            int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int minRight2 = (partition2 == len2) ? INT_MAX : nums2[partition2];
            
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                if (totalLength % 2 == 1)
                    return max(maxLeft1, maxLeft2);
                else
                    return ((double)(max(maxLeft1, maxLeft2) + min(minRight1, minRight2))) / 2.0;
            }
            else if (maxLeft1 > minRight2) {
                high = partition1 - 1;
            }
            else {
                low = partition1 + 1;
            }
        }
        
        return 0; // This line should never be reached if the inputs are valid and sorted.
    }
};
