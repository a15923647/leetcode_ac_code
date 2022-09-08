vector<string> id2s;
unordered_map<string, int> s2id;

struct ticket {
  int idx;
  bool used;
};

bool compare(ticket i, ticket j) {
  return id2s[i.idx] < id2s[j.idx];
}

class Solution {
  public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
      //vector<int> s2id(26*26*26, -1), id2s(300);//used unordered_map instread for convenience
      s2id.clear();
      id2s.clear();
      
      unsigned n = 0;
      vector<vector<ticket>> adj_list;
      //build adjacent list
      for (vector<string>& tkt : tickets) {
        string from = tkt[0], to = tkt[1];
        if (!s2id.count(from)) {
          s2id[from] = n++;
          id2s.push_back(from);
          adj_list.push_back({});
        }
        if (!s2id.count(to)) {
          s2id[to] = n++;
          id2s.push_back(to);
          adj_list.push_back({});
        }
        int from_id = s2id[from], to_id = s2id[to];
        adj_list[from_id].push_back(ticket{to_id, false});
      }
      //sort all to vectors in adj_list by lexicon order
      for (auto& tos : adj_list) {
        sort(tos.begin(), tos.end(), compare);
      }
      
      vector<string> ans(1, "JFK");
      dfs(s2id["JFK"], tickets.size()+1, adj_list, ans);
      return ans;
    }
    //       current stop, total stops, adj_list, current path
    void dfs(int cur, int total, vector<vector<ticket>>& adj_list, vector<string>& path) {
      //all tickets are used
      if (path.size() == total) return;
      
      for (auto& nei : adj_list[cur]) {
        if (!nei.used) {
          path.push_back(id2s[nei.idx]);
          nei.used = true;
          dfs(nei.idx, total, adj_list, path);
          //a path is found
          if (path.size() == total) return;
          //next stop cannot be nei, roll back
          path.pop_back();
          nei.used = false;
        }
      }
    }
};
