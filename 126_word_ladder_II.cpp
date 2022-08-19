static inline bool adjacent(string& a, string& b) {
  const size_t len = a.length();
  size_t i;
  //find first difference
  for (i = 0; i < len && a[i] == b[i]; i++);
  //if a == b, now, i = len
  if (i == len) return false;
  //a != b, find second difference
  for (i = i+1; i < len && a[i] == b[i]; i++);
  return (i == len);
}

static inline void build_adj_list(vector<string>& wordList, vector<vector<int>>& adj_list) {
  const int n = wordList.size();
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++)
      if (adjacent(wordList[i], wordList[j])) {
        adj_list[i].push_back(j);
        adj_list[j].push_back(i);
      }
  }
}

class Solution {
  public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
      if (find(wordList.begin(), wordList.end(), beginWord) == wordList.end())
        wordList.push_back(beginWord);
      vector<vector<string>> ans;
      int end = find(wordList.begin(), wordList.end(), endWord) - wordList.begin();
      const int n = wordList.size();
      if (end == n)
        return ans;
      
      vector<int> steps;
      vector<vector<int>> adj_list(n, vector<int>());
      build_adj_list(wordList, adj_list);
      int begin = find(wordList.begin(), wordList.end(), beginWord) - wordList.begin();
      
      bfs(begin, end, adj_list, steps);
      
      vector<string> path;
      get_answers(end, adj_list, steps, wordList, path, ans);
      
      return ans;
    }
    void bfs(int begin, int end, vector<vector<int>>& adj_list, vector<int>& steps) {
      queue<int> q;
      q.push(begin);
      
      const int n = adj_list.size();
      bool visited[n];
      memset(visited, false, n * sizeof(bool));
      steps = vector<int>(n, INT_MAX);
      
      for(int cur_step = 0; !q.empty() && !visited[end]; cur_step++) {
        int size = q.size();
        //cout << size << endl;
        while (size--) {
          int cur = q.front(); q.pop();
          if (visited[cur]) continue;
          steps[cur] = cur_step;
          visited[cur] = true;
          for (int nei : adj_list[cur]) {
            if (!visited[nei]) {
              q.push(nei);
            }
          }
        }
      }
    }
    
    void get_answers(int i, vector<vector<int>>& adj_list, const vector<int>& steps, vector<string>& wordList, vector<string>& path, vector<vector<string>>& ans) {
      path.push_back(wordList[i]);
      if (steps[i] == 0) {
        vector<string> an_ans(path);
        reverse(an_ans.begin(), an_ans.end());
        ans.push_back(an_ans);
        path.pop_back();
        return;
      }
      
      for (int nei : adj_list[i]) {
        if (steps[nei] == steps[i]-1) {
          get_answers(nei, adj_list, steps, wordList, path, ans);
        }
      }
      path.pop_back();
    }
};