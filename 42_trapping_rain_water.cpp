class Solution {
  public:
    int trap(vector<int>& height) {
      int lower, level = 0, l = 0, r = height.size()-1, ans = 0;
      while (l < r) {
        lower = height[height[l] < height[r] ? l++ : r--];
        level = max(level, lower);
        ans += level - lower;
      }
      return ans;
    }
};