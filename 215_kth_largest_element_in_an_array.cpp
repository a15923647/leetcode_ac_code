#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      if (k < (nums.size() >> 1)) {
        mergeSort(nums, 0, nums.size()-1, k, false);
        return nums[k-1];
      }
      mergeSort(nums, 0, nums.size()-1, nums.size()-k+1, true);
      return nums[nums.size()-k];
    }
    //1 - k - size
    //0 - k-1 - size-1
    //sorted[kth-1] == sorted[size-kth]
    void mergeSort(vector<int>& nums, int l, int r, int kth, bool ascend=true) {
      if (l == r) return;
      int mid = l + ((r-l)>>1);
      mergeSort(nums, l, mid, kth, ascend);
      mergeSort(nums, mid+1, r, kth, ascend);
      
      int insert_cnt = min((r-l+1), kth);
      //int insert_cnt = r-l+1;
      vector<int> tmp; tmp.resize(r-l+1);
      copy(nums.begin()+l, nums.begin()+r+1, tmp.begin());
      //for (int i = 0; i <= r-l; i++) tmp[i] = nums[l+i];
      for (int i = 0, j = mid-l+1, k = l; insert_cnt > 0; k++, insert_cnt--) {
        if (i <= mid - l && j <= r - l) {
          if (ascend) nums[k] = (tmp[i] < tmp[j]) ? tmp[i++] : tmp[j++];
          else nums[k] = (tmp[i] > tmp[j]) ? tmp[i++] : tmp[j++];
        } else if (i <= mid-l)
          nums[k] = tmp[i++];
        else
          nums[k] = tmp[j++];
      }
    }
};