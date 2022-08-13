struct container {
  public:
    vector<int> collection;
    int i;
    container() : collection(vector<int>()), i(0) {};
    container(int first_idx) : collection(vector<int>(1, first_idx)), i(0) {};
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      map<int, container> num2idx;
      int cur;
      for (int i = 0; i < nums.size(); i++) {
        cur = nums[i];
        if (num2idx.count(cur) == 0) {
          num2idx[cur] = container(i);
          continue;
        }
        num2idx[cur].collection.push_back(i);
      }
      for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        int remain = target - num;
        num2idx[num].i++;
        if (num2idx.count(remain)) {
          container& remain_cont = num2idx[remain];
          if(remain_cont.i >= remain_cont.collection.size())
            continue;
          vector<int> ans(1, i);
          ans.push_back(remain_cont.collection[remain_cont.i++]);
          return ans;
        }
        num2idx[num].i--;
      }
      return vector<int>();
    }
};