//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/discuss/167981/Beats-100-Binary-Search-with-Explanations
class Solution {
  public:
    int findMin(vector<int>& nums) {
      //keep minimum index within [l, h]
      int l = 0, h = nums.size()-1;
      //cut out sorted part
      while (l < h) {
        int mid = l + ((h-l) >> 1);
        if (nums[mid] < nums[l]) {//[l, mid] is not sorted, cut out [mid+1, h], min is in [l+1, mid]
          h = mid;
          l++;
        } else if (nums[mid] > nums[h]) {//[mid, h] is not sorted, cut out [l, mid], min is in [mid+1, h]
          l = mid+1;
        //(nums[mid] >= nums[l]) && (nums[mid] <= nums[h]), i.e. nums[l] <= nums[mid] <= nums[h] and min is within
        } else {
          if (nums[l] < nums[h]) return nums[l];
          h--;
        }
      }
      return nums[l];
    }
};