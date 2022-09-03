class Solution {
  public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
      int ans = 1;
      const size_t m = matrix.size();
      const size_t n = matrix[0].size();
      dp = vector<vector<int>>(m, vector<int>(n, 0));
      for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
          ans = max(ans, dfs(matrix, i, j));
      return ans;
    }
    int dfs(vector<vector<int>>& matrix, int i, int j) {
      if (dp[i][j]) return dp[i][j];
      int max_len = 1;
      const size_t m = matrix.size(), n = matrix[0].size();
      int new_i, new_j;
      for (auto dir : dirs) {
        new_i = i + dir[0];
        new_j = j + dir[1];
        if (new_i < 0 || new_i >= m || new_j < 0 || new_j >= n || matrix[new_i][new_j] <= matrix[i][j])
          continue;
        max_len = max(max_len, 1 + dfs(matrix, new_i, new_j));
      }
      return dp[i][j] = max_len;
    }
    const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> dp;
};