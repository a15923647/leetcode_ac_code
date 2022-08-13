#include <regex>

class Solution {
  public:
    Solution() {
      reg = regex("[+-]?(([0-9]+\\.?[0-9]*)|(\\.[0-9]+))([eE][+-]?[0-9]+)?");
    }
    bool isNumber(string s) {
      return regex_match(s, reg);
    }
    regex reg;
};