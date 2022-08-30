class Solution {
  public:
    int countDigitOne(int n) {
      size_t cnt = 0;
      for (size_t nd = 1; nd <= n; nd *= 10) {
        /*
        n = 21012
        nd     a       b     a.last  if "1" at last of a
        1,     21012         2       2102 * 1, [case a.last > 1] 2102 means the prefix range in [0, 2101]
        10,    2101    2     1       210 * 10 + 3, [case a.last = 1] since a.last = 1, 210 means when prefix in [0, 209], suffix can in [0, 9]; 3 means b+1
        100,   210     12    0       21 * 100 + 0, [case a.last = 0] since a.last = 0, 21 means prefix in [0, 20], no 21 *1* XX <= 21012
        1000,  21      012   1       2 * 1000 + 13, [case a.last > 1] simiar to nd = 10
        10000, 2       1012  2       1 * 10000 + 0, [case a.last = 2]
        */
         size_t a = n / nd, b = n % nd;
         cnt += ((a+8) / 10) * nd + (a % 10 == 1) * (b+1);
      }
      return cnt;
    }
};