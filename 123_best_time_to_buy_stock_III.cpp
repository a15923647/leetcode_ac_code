#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int maxProfit(vector<int>& prices) {
      /*
      Since two transaction cannot overlap, 
      we can using cut to split the entire range into two segments, [0, cut] and [cut+1, n).
      Then, do at most one transaction on each.
      ## implemenation idea:
      Define two dp array
      dpl[cut] = max profit in [0, cut]
      dpr[cut] = max profit in [cut+1, n)
      Our goal is to find out a cut which dpl[cut]+dpr[cut] is the greatest.
      */
      const size_t n = prices.size();
      if (n <= 1) return 0;
      size_t dpl[n], dpr[n];
      dpl[0] = dpr[n-1] = 0;
      //construct dpl
      size_t low = prices[0], high = prices[0];
      for (size_t i = 1; i < n; i++) {
        size_t cur_h = prices[i];
        dpl[i] = dpl[i-1];
        if (cur_h < low) {
          low = high = cur_h;
        } else if (cur_h > high) {
          high = cur_h;
          dpl[i] = max(dpl[i], high - low);
        }
      }
      //construct dpr
      low = high = prices[n-1];
      for (int i = n-2; i >= 0; i--) {
        size_t cur_h = prices[i];
        dpr[i] = dpr[i+1];
        if (cur_h < low) {
          low = cur_h;
          dpr[i] = max(dpr[i], high - low);
        } else if (cur_h > high) {
          low = high = cur_h;
        }
      }
      int ans = 0;
      for (size_t cut = 1; cut < n; cut++) {
        ans = max(ans, (int)(dpl[cut]+dpr[cut]));
      }
      return ans;
    }
};

int main(void) {
  Solution sol;
  vector<int> prices({7,6,4,3,1});
  cout << sol.maxProfit(prices) << endl;
  return 0;
}