class Solution {
  public:
    int longestValidParentheses(string s) {
      stack<int> st;
      const int len = s.length();
      for (int i = 0; i < len; i++) {
        if (s[i] == '(') st.push(i);
        else {
          if (!st.empty()) {
            if (s[st.top()] == '(') st.pop();
            else st.push(i);
          } else {
            st.push(i);
          }
        }
      }
      if (st.empty()) return len;
      int seg_l, seg_r = len;
      int ans = 0;
      while (!st.empty()) {
        seg_l = st.top(); st.pop();
        ans = max(ans, seg_r - seg_l -1);
        seg_r = seg_l;
      }
      ans = max(ans, seg_r);
      return ans;
    }
};