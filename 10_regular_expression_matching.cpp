#define MATCH(c, p) (((p) == '.') || ((c) == (p)))
#define invalid 2
class Solution {
public:
  bool node(string &s, int i, string &p, int j) {
    if (dp[i][j] != invalid) return dp[i][j];
    if (j == p.size()) {
		  return dp[i][j] = (i == s.size());
	  }
	  
    bool first_match = (i < s.size()) && MATCH(s[i], p[j]);
	  if (j + 1 < p.size() && p[j+1] == '*') {
		  return dp[i][j] = node(s, i, p, j+2) || (first_match && node(s, i+1, p, j));
	  }
	  
	  
	  return dp[i][j] = first_match && node(s, i+1, p, j+1);//not match, rejects
	}
  bool isMatch(string s, string p) {
      dp = vector<vector<short>> (s.size()+1, vector<short>(p.size()+1, invalid));
    return node(s, 0, p, 0);
  }
  vector<vector<short>> dp;
};