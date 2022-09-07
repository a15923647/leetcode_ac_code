class Solution {
  public:
    int minPatches(vector<int>& nums, int n) {
      //suppose we can have any number within [0, req).
      const size_t nums_len = nums.size();
      long long req = 1;
      int ans = 0, i = 0;
      while (req <= n) {
        //we already have a potential number to push req.
        //[0, req) + [0 + nums[i], req + nums[i]) = [0, req + nums[i])
        //nums[i] <= req makes sure that two interval above are continuous.
        if (i < nums_len && nums[i] <= req) {
          req += nums[i++];
          
        //[0, req) + [0+req, req+req) = [0, 2req)
        } else {
          req <<= 1;
          ans++;
        }
      }
      return ans;
    }
};