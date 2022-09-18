class Solution {
  public:
    string convert(string s, int numRows) {
      if (numRows <= 1) return s;
      string res;
      const size_t len = s.length();
      const size_t group_size = 2 * numRows - 2;
      for (int line = 0; line < numRows; line++) {
        for (int j = line; j < len; j += group_size) {
          res += s[j];
          int second_idx = (j - line) + group_size - line;
          if (line != 0 && line != numRows-1 && second_idx < len)
            res += s[second_idx];
        }
      }
      return res;
    }
};