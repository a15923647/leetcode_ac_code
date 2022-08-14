#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int largestRectangleArea(vector<int>& heights) {
      stack<int> left_inds({-1});
      const int n = heights.size();
      int cur_h, ans = 0;
      for (int i = 0; i < n; i++) {
        cur_h = heights[i];
        while (left_inds.top() >= 0 && cur_h < heights[left_inds.top()]) {
          int ind = left_inds.top(); left_inds.pop();
          int width = i - left_inds.top() - 1;
          ans = max(ans, width * heights[ind]);
        }
        left_inds.push(i);
      }
      while (left_inds.top() >= 0) {
        int ind = left_inds.top(); left_inds.pop();
        int width = n - left_inds.top() - 1;
        ans = max(ans, width * heights[ind]);
      }
      return ans;
    }
};