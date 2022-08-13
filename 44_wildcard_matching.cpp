#define invalid -1
int dp[2002][2002];
class Solution {
public:
    bool isMatch(string s, string p) {
        //*: passing any number of input subsequence
        //more specifically, to increase efficency, find next matching character
        //? || match: match next
        memset(dp, invalid, sizeof(dp));
        return _isMatch(s, 0, p, 0);
    }
    bool _isMatch(string& s, int i, string& p, int j) {
      //cout << i << " " << s[i] << " " << j << " " << p[j] << endl;
      if (dp[i][j] != invalid) return dp[i][j];
      if (j == p.size()) return i == s.size();
      if (p[j] == '?' || p[j] == s[i]) return dp[i][j] = (i < s.size()) && _isMatch(s, i+1, p, j+1);
      if (p[j] == '*') {
        //match any number of character
        //* on tail of pattern
        if (j+1 == p.size()) return dp[i][j] = true;
        //pass this * or ignore one character
        return dp[i][j] = _isMatch(s, i, p, j+1) || ((i < s.size()) && _isMatch(s, i+1, p, j));
      }
      return dp[i][j] = false;//s[i] != '?' or '*' or p[j]
    }
    
};