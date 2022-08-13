#include <bits/stdc++.h>
#define LC(x) ((x)<<1)
#define RC(x) (((x)<<1)+1)
#define NEXT_POW2(x) (1 << (int)(ceil(log2(x))+1))
#define TARGET_FUNC max
#define UPDATE_FUNC max
using namespace std;
class Solution {
  public:
    vector<int> tree;
    vector<int> lazy;
    vector<bool> mark;
    int x_len;
    void init(int n) {
      x_len = n;
      int v_size = NEXT_POW2(n);
      tree = vector<int>(v_size, 0);
      lazy = vector<int>(v_size, 0);
      mark = vector<bool>(v_size, 0);
    }
    void deal_mark(int cur_idx, int l, int r) {
      if (mark[cur_idx]) {
        //clear
        int lz = lazy[cur_idx];
        tree[cur_idx] = TARGET_FUNC(tree[cur_idx], lz);
        //cout << "update tree[" << cur_idx << "] to " << tree[cur_idx] << endl;
        lazy[cur_idx] = 0;
        mark[cur_idx] = false;
        //push
         lazy[LC(cur_idx)] = TARGET_FUNC(lazy[LC(cur_idx)], lz);
         lazy[RC(cur_idx)] = TARGET_FUNC(lazy[RC(cur_idx)], lz);
         mark[LC(cur_idx)] = mark[RC(cur_idx)] = true;
      }
    }
    void update(int ustart, int uend, int val) {
      _update(ustart, uend, val, 0, x_len-1, 1);
    }
    void _update(int ustart, int uend, int val, int l, int r, int cur_idx) {
      //cout << "call _update " << ustart << " " << uend << " " << val << " " << l << " " << r << " " << cur_idx << endl;
      //if (l > r || ustart > r || uend < l) return;
      if (ustart == l && uend == r) {
        lazy[cur_idx] = TARGET_FUNC(lazy[cur_idx], val);
        mark[cur_idx] = true;
        //cout << "update lazy to " << lazy[cur_idx] << endl;
        return;
      }
      deal_mark(cur_idx, l, r);
      int mid = l + ((r-l) >> 1);
      if (ustart <= mid) _update(ustart, min(mid, uend), val, l, mid, LC(cur_idx));
      if (uend > mid) _update(max(mid+1, ustart), uend, val, mid+1, r, RC(cur_idx));
    }
    int query(int qstart, int qend) {
      return _query(qstart, qend, 0, x_len-1, 1);
    }
    int _query(int qstart, int qend, int l, int r, int cur_idx) {
      if (qstart == l && qend == r) {
        //cout << "return " << tree[cur_idx] << endl;
        if (mark[cur_idx]) {
            mark[cur_idx] = false;
            return tree[cur_idx] = UPDATE_FUNC(tree[cur_idx], lazy[cur_idx]);
        }
        return tree[cur_idx];
      }
      deal_mark(cur_idx, l, r);
      int mid = l + ((r-l) >> 1);
      int cur_ans = 0;
      if (qstart <= mid) cur_ans = TARGET_FUNC(cur_ans, _query(qstart, min(mid, qend), l, mid, LC(cur_idx)));
      if (qend > mid) cur_ans = TARGET_FUNC(cur_ans, _query(max(mid+1, qstart), qend, mid+1, r, RC(cur_idx)));
      return cur_ans;
    };
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
      set<int> key_candidates;
      for(auto& b : buildings) {
        key_candidates.insert(b[0]);
        key_candidates.insert(b[1]);
      }
      init(key_candidates.size());
      unordered_map<int, int> pseu;
      vector<int> real;
      for(auto& x : key_candidates) {
        pseu[x] = real.size();
        real.push_back(x);
      }
      for(auto& v : buildings)
        update(pseu[v[0]], pseu[v[1]]-1, v[2]);
      int cur_height, past_height = 0;
      vector<vector<int>> ans;
      //cout << "update complete\n";
      for(int i = 0; i < x_len; i++) {
        cur_height = query(i, i);
        //cout << cur_height << " " << past_height << endl;
        if (cur_height == past_height) continue;
        ans.push_back({real[i], cur_height});
        past_height = cur_height;
      }
      return ans;
    }
};
