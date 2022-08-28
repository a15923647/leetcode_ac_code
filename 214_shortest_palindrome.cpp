class Solution {
  public:
    string shortestPalindrome(string s) {
      string rs = s;
      reverse(rs.begin(), rs.end());
      string cat = s + "#" + rs;
      
      //find LSP
      vector<int> next(cat.size(), 0);
      for (int part = 0, whole = 1; whole < cat.size(); whole++) {
        while (part > 0 && cat[part] != cat[whole])
          part = next[part-1];
        
        if (cat[part] == cat[whole])
          part++;
        
        next[whole] = part;
      }
      int mismatches = s.length() - next.back();
      string append_front = rs.substr(0, mismatches);
      return append_front + s;
    }
};