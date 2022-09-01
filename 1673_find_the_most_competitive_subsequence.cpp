class Solution {
  public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
      const int len = nums.size();
      vector<int> ans;
      for (int i = 0; i < len; i++) {
        int after = len - i;
        //                                             need < after (input is sufficient)
        while (!ans.empty() && ans.back() > nums[i] && k - ans.size() < after) {
          ans.pop_back();
        }
        if (ans.size() < k) ans.push_back(nums[i]);
      }
      return ans;
    }
};