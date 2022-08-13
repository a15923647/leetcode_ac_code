#define COL_MASK(col) (1 << (col))
#define ADD_MASK(row, col) (1 << ((row)+(col)))
#define SUB_MASK(row, col) (1 << ((row)-(col)+size))
#define SET_BIT(p,mask) ((p) |= (mask))
#define CLR_BIT(p,mask) ((p) &= ~(mask))
class Solution {
  public:
    int totalNQueens(int n) {
      if (n == 1) {
        return 1;
      }
      size = n;
      ans = column_state = add_state = sub_state = 0;
      place_row(0);
      return ans;
    }
    void place_row(unsigned short row) {
      if (row == size) {
        ans++;
        return;
      }
      for (unsigned short col = 0; col < size; col++) {
        const unsigned col_m = COL_MASK(col), add_m = ADD_MASK(row, col), sub_m = SUB_MASK(row, col);
        if (!(column_state & col_m) && !(add_state & add_m) && !(sub_state & sub_m)) {
          SET_BIT(add_state, add_m);
          SET_BIT(sub_state, sub_m);
          SET_BIT(column_state, col_m);
          place_row(row+1);
          CLR_BIT(add_state, add_m);
          CLR_BIT(sub_state, sub_m);
          CLR_BIT(column_state, col_m);
        }
      }
    }
    unsigned short size;
    int ans;
    unsigned add_state;
    unsigned sub_state;
    unsigned short column_state;
};