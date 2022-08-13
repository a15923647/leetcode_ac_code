#include <bits/stdc++.h>
#define LOWBIT(x) ((x)&(-(x)))
using namespace std;
template <class T>
class BIT {
  public:
    BIT(int n): data_size(n+1) {
        bit_data = new T[n+1];
    }
    void init(T *ptr) {
        T tmp[data_size];
        tmp[0] = 0;
        for (int i = 1; i < data_size; i++)
            tmp[i] = tmp[i-1] + ptr[i-1];
        for (int i = 1; i < data_size; i++)
            bit_data[i] = tmp[i] - tmp[i-LOWBIT(i)];
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
  private:
    T *bit_data;
    int data_size;
};

class NumArray {
  public:
    NumArray(vector<int>& nums) {
      _nums = nums.data();
      p = new BIT<int>(nums.size());
      p->init(_nums);
    }
    void update(int index, int val) {
      this->p->update(index+1, val-_nums[index]);
      _nums[index] = val;
    }
    int sumRange(int left, int right) {
      return this->p->query(right+1) - this->p->query(left);
    }
    BIT<int> *p;
    int *_nums;
};
