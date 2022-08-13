#include <bits/stdc++.h>
using namespace std;
void show_v(vector<int>& nums) {
  for (int e: nums)
    cout << e << " ";
  cout << endl;
}
class Solution {
  public:
    int reversePairs(vector<int>& nums) {
      //use merge sort to count segments
      return mergeSort(nums, 0, nums.size()-1);
    }
    //return count of i-j pairs which nums[i] > 2 * nums[j] for i, j within [l, r].
    int mergeSort(vector<int>& nums, int l, int r) {
      if (l == r) return 0;
      int mid = l + ((r-l) >> 1);
      int count = mergeSort(nums, l, mid) + mergeSort(nums, mid+1, r);
      //show_v(nums);
      int leftMin = l, leftMax = l;
      //count i-j pairs which cross mid
      for (int j = mid+1; j <= r; j++) {
        long long num = (long long)nums[j] * 2;//right number * 2
        //nums[left] > num(i.e. 2 * nums[j])
        while (leftMin <= mid && nums[leftMin] <= num)
          leftMin++;
        leftMax = max(leftMax, leftMin);
        while (leftMax <= mid && nums[leftMax] > num)
          leftMax++;
        count += (leftMax-leftMin);
      }
      //sort two halves
      int cnt = r-l+1;
      vector<int> tmp;
      tmp.resize(cnt);
      copy(nums.begin()+l, nums.begin()+r+1, tmp.begin());
      for (int i = 0, j = mid-l+1, k=l; cnt > 0; cnt--, k++) {
        if (i <= mid-l && j <= r-l)
          nums[k] = (tmp[i] < tmp[j]) ? tmp[i++] : tmp[j++];
        else if (i <= mid-l)
          nums[k] = tmp[i++];
        else
          nums[k] = tmp[j++];
      }
      //cout << "mergeSort " << l << " " << r << " returns " << count << endl;
      return count;
    }
};