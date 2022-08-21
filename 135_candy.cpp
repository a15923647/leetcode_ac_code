//https://leetcode.com/problems/candy/discuss/42769/A-simple-solution
class Solution {
  public:
    int candy(vector<int>& ratings) {
      const int len = ratings.size();
      vector<int> cans(len, 1);
      //Do it in two directions.
      //children with a higher rating get more candy than its left neighbor
      for (int i = 1; i < len; i++) {
        if (ratings[i] > ratings[i-1])
          cans[i] = cans[i-1] + 1;
      }
      //children with a higher rating get more candy than its right neighbor.
      for (int i = len-1; i > 0; i--) {
        if (ratings[i-1] > ratings[i])
          cans[i-1] = max(cans[i]+1, cans[i-1]);
      }
      int ans = 0;
      for (auto e : cans)
        ans += e;
      return ans;
    }
};