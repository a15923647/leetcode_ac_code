//source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/39608/A-clean-DP-solution-which-generalizes-to-k-transactions/37347
class Solution {
  public:
    int maxProfit(int k, vector<int>& prices) {
      const size_t n = prices.size();
      if (n < 2) return 0;
      if (k >= (n >> 1)) {
        int ans = 0;
        for (size_t i = 1; i < n; i++)
          ans += max(0, prices[i] - prices[i-1]);
        return ans;
      }
      /*
      f[k][i]: max profit in the first i days with at most k transactions
      g[k][i]: max profit in the first i days with at most k transactions and sales on day i
      
      f[k][i] = max ( f[k][i-1], g[k][i] )
                      not sale   sale
      g[k][i] = max( p[i] - p[j] + f[k-1][j] for j in range(i) )
                                                 buy on someday before
              //fixed p[i] for max
              = p[i] + max(f[k-1][j] - p[j] for j in range(i))
              //range(i) = range(i-1) + case i-1
              = p[i] + max( max(f[k-1][j]-p[j] for j in range(i-1)), f[k-1][i-1] - p[i-1] )
              //extract p[i-1] out of outter max
              = p[i] - p[i-1] + max( p[i-1] + max(f[k-1][j]-p[j] for j in range(i-1)), f[k-1][i-1] )
              //first argument in outter max is exactly g[k][i-1]
              = max ( g[k][i-1], f[k-1][i-1]) ) + p[i] - p[i-1]   
      
      f[k][i] requires info of i-1                      -
                                                         | -> outter loop
      g[k][i] requires info of i-1, k-1  //inner loop   -
      */
      vector<int> f(k+1, 0), g(k+1, 0);
      for (int i = 1; i < n; i++) {
        for (int kk = 1, tmp=f[0], diff = prices[i] - prices[i-1]; kk <= k; kk++) {
          g[kk] = max(g[kk], tmp) + diff;
          tmp=f[kk];
          f[kk] = max(tmp, g[kk]);
        }
      }
      return f[k];
    }
};
