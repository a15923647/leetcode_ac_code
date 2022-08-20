class Solution {
  public:
    int minCut(string s) {
      const int n = s.length();
      dp = vector<vector<int>>(n, vector<int>(n, -1));
      chkdp = vector<vector<bool>>(n+1, vector<bool>(n+1));
      chkvalid = vector<vector<bool>>(n+1, vector<bool>(n+1, false));
      return solve(s, 0, n-1);
    }
    int solve(string& s, int left, int right) {
        if (dp[left][right] != -1) return dp[left][right];
        if (left >= right || isPalindrome(s, left, right)) return dp[left][right] = 0;
        int ans = INT_MAX;
        for (int center = left; center < right; center++) {
            if (!isPalindrome(s, left, center)) continue;
            int temp_ans = solve(s, left, center) + solve(s, center+1, right) + 1;
            ans = min(ans, temp_ans);
        }
        return dp[left][right] = ans;
    }
    
    bool isPalindrome(string& s, int start, int end) {
      if (start > end) return false;
      if (chkvalid[start][end]) return chkdp[start][end];
      
      chkvalid[start][end] = true;
      if (end - start <= 1) {
        return chkdp[start][end] = (s[start] == s[end]);
      }
      return chkdp[start][end] = ((s[start] == s[end]) && isPalindrome(s, start+1, end-1));
    }
    vector<vector<int>> dp;
    vector<vector<bool>> chkdp;
    vector<vector<bool>> chkvalid;
};