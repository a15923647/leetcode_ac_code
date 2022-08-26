class Solution {
  public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
      const size_t m = dungeon.size();
      const size_t n = dungeon[0].size();
      int dp[n]; int i;
      //last row, only choice is moving to right
      for (i = n-2, dp[n-1] = max(1, 1-dungeon[m-1][n-1]); i >= 0; i--) {
        dp[i] = max(1, dp[i+1]-dungeon[m-1][i]);
      }
      int r;
      //for row other than first row
      for (r = m-2; r >= 0; r--) {
        //last column, only choice is going down
        dp[n-1] = max(1, dp[n-1]-dungeon[r][n-1]);
        for (i = n-2; i >= 0; i--) {
          //min HP     go downward                  to rightward
          dp[i] = min( max(1, dp[i]-dungeon[r][i]), max(1, dp[i+1]-dungeon[r][i]) );
        }
      }
      return dp[0];
    }
};