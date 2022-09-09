static inline void insert(map<int, int>& buckets, int val) {
  if (!buckets.count(val)) buckets[val] = 0;
    buckets[val]++;
}
static inline void remove(map<int, int>& buckets, int val) {
  if (--buckets[val] == 0)
    buckets.erase(val);
}
static inline bool search(map<int, int>& buckets, int center, int valueDiff) {
  int left = center - valueDiff;
  int right = center + valueDiff;
   
  std::map<int,int>::iterator it, up;
  size_t cnter;
  for (it = buckets.lower_bound(left), up = buckets.upper_bound(right), cnter = 0; cnter < 2 && it != up; it = next(it)) {
    cnter += it->second;
  }
  return cnter >= 2;
}

class Solution {
  public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
      const size_t nums_size = nums.size();
      map<int, int> buckets;
      
      const size_t window_size = min((size_t)indexDiff+1, nums.size());
      //init first window
      int i = 0, j;//[i, j)
      for (j = 0; j < window_size; j++) {
        insert(buckets, nums[j]);
        if (search(buckets, nums[j], valueDiff)) {
          return true;
        }
      }
      //sliding window
      while (j < nums_size) {
        remove(buckets, nums[i++]);
        insert(buckets, nums[j]);
        if (search(buckets, nums[j++], valueDiff)) {
          return true;
        }
      }
      return false;
    }
    
};