//https://leetcode.com/problems/burst-balloons/discuss/892552/For-those-who-are-not-able-to-understand-any-solution-WITH-DIAGRAM
class Solution {
  public:
    int maxCoins(vector<int>& nums) {
      size_t n = nums.size();
      nums.insert(nums.begin(), 1);
      nums.push_back(1);
      dp = vector<vector<int>>(n+2, vector<int>(n+2, -1));
      return solve(nums, 1, n);
    }
    int solve(vector<int>& nums, int i, int j) {
      if (i > j) return 0;
      if (dp[i][j] != -1) return dp[i][j];
      int ans = -1;
      //k: index of last ballon
      //profix = solve(nums, i, k-1) + solve(nums, k+1, j)
      //iterate all cases
      for (int k = i; k <= j; k++) {
        int cur = solve(nums, i, k-1) + solve(nums, k+1, j) + nums[i-1] * nums[k] * nums[j+1];
        ans = max(ans, cur);
      }
      return dp[i][j] = ans;
    }
    vector<vector<int>> dp;
};