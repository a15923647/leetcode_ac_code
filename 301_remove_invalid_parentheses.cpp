static bool valid(string& s) {
  int cnter = 0;
  for (char c : s) {
    if (c == '(') cnter++;
    else if (c == ')') 
      if (--cnter < 0) 
        return false;
  }
  return cnter == 0;
}
class Solution {
  public:
    vector<string> removeInvalidParentheses(string s) {
      vector<string> ans;
      unordered_set<string> pushed;
      
      queue<string> q;
      q.push(s);
      pushed.insert(s);
      while(!q.empty()) {
        size_t level_size = q.size();
        while (level_size--) {
          string cur = q.front(); q.pop();
          if (valid(cur))
            ans.push_back(cur);
          for (int i = 0; i < cur.size(); i++) {
            if (cur[i] != '(' && cur[i] != ')') continue;
            string can = cur.substr(0, i) + cur.substr(i+1);
            if (!pushed.count(can)) {
              q.push(can);
              pushed.insert(can);
            }
          }
        }
        if (!ans.empty()) break;
      }
      return ans;
    }
};