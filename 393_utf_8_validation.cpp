#define BYTE_MASK 0b11111111
#define IB 0b0
#define IIB 0b110
#define IIIB 0b1110
#define IVB 0b11110
#define CB 0b10
static inline bool check(size_t n, vector<int>& data, int& i) {
  const int end = i + n;
  for (; i < end && i < data.size(); i++) {
    if (((data[i] & BYTE_MASK) >> 6) ^ CB)
      return false;
  }
  return i == end;
}

class Solution {
  public:
    bool validUtf8(vector<int>& data) {
      for (int i = 0; i < data.size(); ) {
        int cur_byte = (data[i] & BYTE_MASK);
        if (!((cur_byte >> 3) ^ IVB)) {
          if (!check(3, data, ++i)) 
            return false;
        } else if (!((cur_byte >> 4) ^ IIIB)) {
          if (!check(2, data, ++i)) 
            return false;
        } else if (!((cur_byte >> 5) ^ IIB)) {
          if (!check(1, data, ++i)) 
            return false;
        } else if (!((cur_byte >> 7) ^ IB)) {
          i++;
          continue;
        } else {
          return false;
        }
      }
      return true;
    }
};