#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
      lb = lower;
      rb = upper;
      int nums_size = nums.size();
      long long prefix_sum[nums_size+1];
      prefix_sum[0] = 0;
      long long prev_sum = 0;
      for (int i = 0; i < nums_size; i++) {
        prev_sum = prefix_sum[i+1] = prev_sum + nums[i];
      }
      return mergeSort(prefix_sum, 0, nums_size);
    }
    //return count of intervals in range[lb, rb] between sums[l, r]
    int mergeSort(long long *sums, int l, int r) {
      if (l == r) return 0;
      int mid = l + ((r-l) >> 1);
      //get sum of interval count within each half
      int count = mergeSort(sums, l, mid) + mergeSort(sums, mid+1, r);
      //compute interval count across two halves.
      int rightMin = mid+1, rightMax = mid+1;
      //sliding window
      //for each number sums[i] in the left half in ascending order
      //get right index range so that [(sums[rightMin] - sums[i]), (sums[rightMax] - sums[i])] is within [lb, rb]
      for (int i = l; i <= mid; i++) {
        long long l_sum = sums[i];
        while(rightMin <= r && (sums[rightMin] - l_sum) < lb)
          rightMin++;
        rightMax = max(rightMax, rightMin);
        while(rightMax <= r && (sums[rightMax] - l_sum) <= rb)
          rightMax++;
        count += (rightMax - rightMin);
      }
      //sort two subarray
      long long tmp[r-l+1];
      memcpy(tmp, sums+l, (r-l+1) * sizeof(long long));
      //sums [l, mid], [mid+1, r]
      //tmp  [0, mid-l], [mid-l+1, r-l]
      for (int i = 0, j =mid-l+1 , k = l; i <= mid-l || j <= r-l; k++) {
        if (i <= mid-l && j <= r-l)
          sums[k] = (tmp[i] < tmp[j]) ? tmp[i++] : tmp[j++];
        else if (i <= mid-l)
          sums[k] = tmp[i++];
        else
          sums[k] = tmp[j++];
      }
      return count;
    }
    int lb, rb;
};