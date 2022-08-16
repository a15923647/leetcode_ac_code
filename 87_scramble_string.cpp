class Solution {
  public:
    bool isScramble(string s1, string s2) {
      if (s1.length() != s2.length()) return false;
      const size_t n = s1.length();
      /*
      dp[i][j][k] = whether s2[j:j+k] is scramble of s1[i:i+k]
      split string into two non-empty substring (len in range[1, n])
      if k == 1:
          for all pair of (i, j), dp[i][j][1] = (s1[i] == s2[j]);
      for k > 1:
          for all pair of (i, j), 
              dp[i][j][k] = 
                  if any 0 < l < k satisfies (dp[i][j][l] && dp[i+l][j+l][l-k]) || (dp[i][j+(k-l)][l] && dp[i+l][j][k-l])
      s1 [i, i+k) = [i, i+l) || [i+l, i+k)
      s2 [j, j+k) = 
      {
        s2[j, j+l) || [j+l, j+k), if not swap
        s2[j, j+(k-l)) || [j+(k-l), j+k), if swap
      }
      */
      bool dp[30][30][31] = {false};
      for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
          dp[i][j][1] = (s1[i] == s2[j]);
      for (size_t k = 2; k <= n; k++) 
        for (size_t i = 0; i + k <= n; i++) 
          for (size_t j = 0; j + k <= n; j++) 
            for (int l = 1; l < k; l++) 
              if ( (dp[i][j][l] && dp[i+l][j+l][k-l]) || (dp[i][j+(k-l)][l] && dp[i+l][j][k-l]) ) {
                dp[i][j][k] = true;
                break;
              }
      return dp[0][0][n];
    }
};