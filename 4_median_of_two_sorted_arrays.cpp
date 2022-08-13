class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      //do merge in merge sort
      int n = nums1.size() + nums2.size();
      int cnt = 2 - (n % 2);
      int mid = (n-1) >> 1;
      vector<int> mids;
      int cur;
      for (int i = 0, j = 0, k = 0; k < n, cnt > 0; k++) {
          if (i < nums1.size() && j < nums2.size()) {
              cur = (nums1[i] < nums2[j]) ? nums1[i++] : nums2[j++];
          } else if (i < nums1.size()) {
              cur = nums1[i++];
          } else { // j < nums2.size()
              cur = nums2[j++];
          }
          if ((k==mid || k==mid+1) && cnt) {
            mids.push_back(cur);
            cnt--;
          }
      }
      return mids.size() == 2 ? ((double)(mids[0]+mids[1]))/2 : (double)mids[0];
    }
};