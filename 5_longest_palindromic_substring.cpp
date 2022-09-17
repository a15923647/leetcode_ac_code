//O(n^2) but slower
static inline bool isPalindrome(string& s, int i, int j, vector<vector<bool>>& dp) {
  //i+1 must be done before i => start: len-1 -> 0
  //j-1 must be done before j => last: 0 -> len-1
  //i <= j must be hold
  /*
    for last from 0 to len-1
      for start from to len-1 to last
        
  */
  return dp[i][j] = (s[i] == s[j] && (j - i <= 1 || dp[i+1][j-1]));
}

class Solution {
  public:
    string longestPalindrome(string s) {
      int max_start = 0, max_last = 0;
      const int len = s.length();
      vector<vector<bool>> dp(len, vector<bool>(len, false));
      for (int last = 0; last < len; last++) {
        for (int start = last; start >= 0; start--) {
          if (isPalindrome(s, start, last, dp) && last - start > max_last - max_start) {
            max_start = start;
            max_last = last;
          }
        }
      }
      string res;
      for (int i = max_start; i <= max_last; i++)
        res += s[i];
      return res;
    }
};
//O(n^3) with smaller constant, faster
/*
static inline bool isPalindrome(string& s, int i, int j) {
  while (i < j)
    if (s[i++] != s[j--])
      return false;
  return true;
}

class Solution {
  public:
    string longestPalindrome(string s) {
      int max_start = 0, max_last = 0;
      const int len = s.length();
      for (int start = 0; start < len; start++) {
        int min_last = start + (max_last - max_start);
        if (min_last >= len) break;
        for(int last = len-1; last > min_last; last--)
          if (isPalindrome(s, start, last)) {
            max_start = start;
            max_last = last;
            break;
          }
      }
      string res;
      for (int i = max_start; i <= max_last; i++)
        res += s[i];
      return res;
    }
};
*/