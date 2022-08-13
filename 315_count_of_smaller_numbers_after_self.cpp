#include <bits/stdc++.h>
#define LOWBIT(x) ((x)&(-(x)))
using namespace std;
template <class T>
class BIT {
  public:
    BIT() {}
    BIT(int n): data_size(n+1) {
        bit_data = new T[n+1];
        for (int i = 0; i < data_size; i++)
            bit_data[i] = 0;
    }
    void update(int i, int dx) {
      while (i < data_size) {
        bit_data[i] += dx;
        i += LOWBIT(i);
      }
    }
    T query(int i) const {
      T sum = 0;
      while (i > 0) {
        sum += bit_data[i];
        i -= LOWBIT(i);
      }
      return sum;
    }
    T *bit_data;
    int data_size;
};

class Solution {
  public:
    vector<int> countSmaller(vector<int>& nums) {
      p = new BIT<int>();
      p->data_size = 20002;
      p->bit_data = new int[p->data_size];
      for (int i = 0; i < p->data_size; i++) p->bit_data[i] = 0;
      vector<int> ans;
      for (int i = nums.size()-1; i >= 0; i--) {
        int idx = nums[i] + 10001;
        ans.push_back(this->p->query(idx-1));//must be reversed later
        this->p->update(idx, 1);
      }
      reverse(ans.begin(), ans.end());
      return ans;
    }
  private:
    BIT<int> *p;
};