//thought: https://leetcode.com/problems/distinct-subsequences/discuss/2432577/explain-simple-c-dp-solution-8-lines-faster-than-9464-of-c-online-submissions
class Solution {
  public:
    int numDistinct(string s, string t) {
      const unsigned s_len = s.length();
      const unsigned t_len = t.length();
      vector<unsigned> dp(t_len+1, 0);
      dp[0] = 1;
      for (int i = 0; i < s_len; i++)
        for (int j = t_len-1; j >= 0 ; j--)
          if (s[i] == t[j]) dp[j+1] += dp[j];
      return (int)dp[t_len];
    }
};