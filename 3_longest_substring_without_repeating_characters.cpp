class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int ans = 0, cur_start = 0;
      map<char, int> appeared_pos;
      for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (appeared_pos.count(c) && appeared_pos[c] >= cur_start) {
          ans = max(ans, i-cur_start);
          cur_start = appeared_pos[c]+1;
        }
        appeared_pos[c] = i;
      }
      ans = max(ans, (int)s.size()-cur_start);
      return ans;
    }
};