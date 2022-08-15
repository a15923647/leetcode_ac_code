/*
Reduce maximalRectangle to n(row count) largestRectangleArea
heights = upper continuous height from current row to row 0.
*/
class Solution {
  public:
    int maximalRectangle(vector<vector<char>>& matrix) {
      vector<int> heights(matrix[0].size(), 0);
      const size_t width = matrix[0].size();
      int ans = 0;
      for (auto &row : matrix) {
        for (int j = 0; j < width; j++) {
          //heights[j] = (row[j] == '1') ? heights[j]+1 : 0;
          //'0' = 0b110000, '1' = 0b110001
          heights[j] = (row[j] & 1) ? heights[j]+1 : 0;
        }
        ans = max(ans, largestRectangleArea(heights));
      }
      return ans;
    }
    //https://github.com/a15923647/leetcode_ac_code/blob/main/84_largest_rectangle_histogram.cpp
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