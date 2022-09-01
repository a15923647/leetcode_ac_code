//https://leetcode.com/problems/create-maximum-number/discuss/1917528/C%2B%2B-Intuition-wreference-question-or-Stack-and-Merge-sort-Concept
class Solution {
  public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
      vector<int> ans;
      for (int i = 0; i <= k; i++) {
        vector<int> a = findKMax(nums1, i);
        vector<int> b = findKMax(nums2, k-i);
        if (a.size() + b.size() < k) continue;
        vector<int> m;
        merge(a, b, m);
        ans = max(ans, m);
      }
      return ans;
    }
    //https://leetcode.com/problems/find-the-most-competitive-subsequence/
    vector<int> findKMax(vector<int>& nums, int k) {
      const int len = nums.size();
      vector<int> ans;
      for (int i = 0; i < len; i++) {
        int after = len - i;
        //                                             need < after (input is sufficient)
        while (!ans.empty() && ans.back() < nums[i] && k - ans.size() < after) {
          ans.pop_back();
        }
        if (ans.size() < k) ans.push_back(nums[i]);
      }
      return ans;
    }
    void merge(vector<int> a, vector<int> b, vector<int>& m) {
      //push and pop from vector back is O(1)
      reverse(a.begin(), a.end());
      reverse(b.begin(), b.end());
      while (a.size() && b.size()) {
        vector<int>& large = get_large(a, b);
        m.push_back(large.back());
        large.pop_back();
      }
      while (a.size()) {
        m.push_back(a.back());
        a.pop_back();
      }
      while (b.size()) {
        m.push_back(b.back());
        b.pop_back();
      }
    }
    vector<int>& get_large(vector<int>& a, vector<int>& b) {
      int i = a.size()-1, j = b.size()-1;
      while (i >= 0 && j >= 0 && a[i] == b[j]) {
        i--; j--;
      }
      if (i >= 0 && j >= 0) {
        return (a[i] > b[j]) ? a : b;
      }
      return (j < 0) ? a : b;
    }
};