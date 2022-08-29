#define IS_NUM(x) ((x) >= '0' && (x) <= '9')
enum Type {l_para, pos_sign, neg_sign, num};
struct Item {
  Type type;
  int val;
};

class Solution {
  public:
    int calculate(string s) {
      string sparse;
      for (char c : s)
        if (c != ' ')
          sparse += c;
      sparse = "(" + sparse + ")";
      stack<Item> stk;
      for (int i = 0; i < sparse.size(); i++) {
        char cur = sparse[i];
        if (cur == '(') {
          stk.push(Item{Type::l_para, 0});
        } else if (cur == ')') {
          int cur_res = 0;
          while (stk.top().type != Type::l_para) {
            int cur_num = stk.top().val; stk.pop();
            if (stk.top().type == Type::neg_sign) {
              cur_num *= -1;
              stk.pop();
            } else if (stk.top().type == Type::pos_sign) {
              stk.pop();
            }
            cur_res += cur_num;
          }
          stk.pop();
          stk.push(Item{Type::num, cur_res});
        } else if (cur == '-' && !IS_NUM((i+1 < sparse.size()) ? sparse[i+1] : ' ')) {
          stk.push(Item{Type::neg_sign, 0});
        } else if (cur == '+') {
          stk.push(Item{Type::pos_sign, 0});
        } else { //number
          int tmp = 0;
          int sign = 1;
          if (cur == '-') {
            sign = -1;
            cur = sparse[++i];
          }
          for (; i < sparse.size() && IS_NUM(sparse[i]); i++) {
            tmp = tmp * 10 + (sparse[i] - '0') * sign;
          }
          i--;
          stk.push(Item{Type::num, tmp});
        }
      }
      return stk.top().val;
    }
};
