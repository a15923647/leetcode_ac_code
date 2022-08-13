class Solution {
  public:
    string getPermutation(int n, int k) {
      k--;
      vector<int> remaining(n);
      string ans;
      int fact[n+1]; fact[0] = 1;
      for (int i = 1; i <= n; i++) {
        remaining[i-1] = i;
        fact[i] = fact[i-1] * i;
      }
      for (int i = n; i > 0; i--) {
        int idx = k / fact[i-1];
        ans += (char)('0' + remaining[idx]);
        remaining.erase(remaining.begin()+idx);
        k %= fact[i-1];
      }
      return ans;
    }
};