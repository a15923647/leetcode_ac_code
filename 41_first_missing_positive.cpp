class Solution {
  public:
  int firstMissingPositive(vector<int>& nums) {
    const int n = nums.size();
    //nums[i] should be in the right place
    //i.e. nums[i] = i+1;
    for (int i = 0; i < n; i++) {
      //put nums[i] to the nums[nums[i]-1](right place for nums[i])
      //until nums[i] is exactly nums[i]+1 or the number is out of bound [1, n]
      while (nums[i] > 0 && nums[i] <= n && nums[nums[i]-1] != nums[i])
        swap(nums[i], nums[nums[i]-1]);
    }
    int i;
    for (i = 0; i < n && nums[i] == i+1; i++);
    return i+1;
  }
};