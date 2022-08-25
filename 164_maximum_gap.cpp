#define R 128
#define OFF_ADD 7
class Solution {
  public:
    int maximumGap(vector<int>& nums) {
      const size_t len = nums.size();
      if (len < 2) return 0;
      vector<vector<int>> bkt;
      for (int rs = 0; rs < 32; rs += OFF_ADD) {
        bkt = vector<vector<int>>(R, vector<int>());
        //throw nums into bkt
        for (auto num : nums) {
          bkt[(num >> rs) & (R-1)].push_back(num);
        }
        //grap back to nums
        int idx = 0;
        for (auto& sbk : bkt) {
          for (auto num : sbk)
            nums[idx++] = num;
        }
      }
      int ans = 0;
      for (int i = 1; i < len; i++) {
        ans = max(ans, nums[i]-nums[i-1]);
      }
      return ans;
    }
};
