/*
If r, c represent row, column respectively.
Any queen should hold a unique r+c value (/ line in checkboard) and a unique r-c value (\ line in checkboard).
                               [0, 2n]                                       [-n, n]   where 1 <= n <= 9
Furthermore, each queen should occupy an unique r and an unique c.

# Implementation ideas
Max r+c, r-c range = 19, two unsigned ints is adequate for tracking them.
Besides, remember to use a variable to record which column has been occupied.
Call a function, place(int row) from row 0 row by row.
if (row == n) place current checkboard to ans and return
find a position to place on current row.
If it is found, step into the procedure to find next queen (place(row+1)).
*/
#define COL_MASK(col) (1 << (col))
#define ADD_MASK(row, col) (1 << ((row)+(col)))
#define SUB_MASK(row, col) (1 << ((row)-(col)+size))
#define SET_BIT(p,mask) ((p) |= (mask))
#define CLR_BIT(p,mask) ((p) &= ~(mask))
class Solution {
  public:
    vector<vector<string>> solveNQueens(int n) {
      if (n == 1) {
        return vector<vector<string>>(1, vector<string>(1, "Q"));
      }
      size = n;
      column_state = add_state = sub_state = 0;
      place_row(0);
      return ans;
    }
    void place_row(int row) {
      if (row == size) {
        ans.push_back(current_board);
        return;
      }
      for (int col = 0; col < size; col++) {
        const unsigned col_m = COL_MASK(col), add_m = ADD_MASK(row, col), sub_m = SUB_MASK(row, col);
        if (!(column_state & col_m) && !(add_state & add_m) && !(sub_state & sub_m)) {
          SET_BIT(add_state, add_m);
          SET_BIT(sub_state, sub_m);
          SET_BIT(column_state, col_m);
          string s(size, '.'); s[col] = 'Q';
          current_board.push_back(s);
          place_row(row+1);
          CLR_BIT(add_state, add_m);
          CLR_BIT(sub_state, sub_m);
          CLR_BIT(column_state, col_m);
          current_board.pop_back();
        }
      }
    }
    int size;
    vector<vector<string>> ans;
    vector<string> current_board;
    unsigned add_state;
    unsigned sub_state;
    int column_state;
};