/*
Key idea: 
Try to keep all characters in t in the current window [l, r].
Popout the leftmost character and find it back on the right hand side.
*/
class Solution {
  public:
    string minWindow(string s, string t) {
      //req width: 2^(character size in bit)
      //req[char] = how many char are still needed for forming t within current window [l, r](defined below).
      int req[1<<(sizeof(char) << 3)];
      memset(req, 0, sizeof(req));
      for (const char c : t) 
        req[c]++;
      //missing: how many characters(any type) are still needed to construct t
      size_t l = 0, r = 0, ans_l = 0, ans_r = -1, missing = t.length();
      //leave l in original position and push r forward
      for (; r < s.length(); r++) {
        if (req[s[r]] > 0) //if this character is helpful to form t, missing--
          missing--;
        //No matter required or not, subtract the coherent req position by one.
        //This makes the req value of unhelpful one becomes negative.
        req[s[r]]--;
        if (missing == 0) {
          //find largest l. i.e. remove unhelpful leftmost numbers whose req values are negative.
          while (l < r && req[s[l]] < 0)
            req[s[l++]]++;
          //now, [l, r] is a candidate
          if (ans_r == -1 || r-l < ans_r-ans_l) {
            ans_l = l;
            ans_r = r;
          }
          //remove leftmost character(one in t) and move r forward inside for loop syntax.
          req[s[l++]]++;
          missing++;
        }
      }
      return s.substr(ans_l, ans_r-ans_l+1);
    }
};