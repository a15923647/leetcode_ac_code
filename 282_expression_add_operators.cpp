class Solution {
  public:
    vector<string> addOperators(string num, int target) {
      string prev;
      vector<string> ans;
      foo(num, 0, 0, target, prev, ans);
      return ans;
    }
    void eval(long long a, char op, long long b, long long& res, long long& mul_res) {
      switch(op) {
        case '+':
          res = a + b + mul_res;
          mul_res = 0;
          break;
        case '-':
          res = a - b + mul_res;
          mul_res = 0;
          break;
        case '*':
          //don't know previous sign, deal in calling function
          //if (mul_res == 0) mul_res = a;
          mul_res *= b;
          res += mul_res;
          break;
        case ' ':
          res = b;
          break;
        default:
          cerr << "invalid operator\n";
          exit(1);
      }
      
    }
    void foo(string nums, long long cur, long long mul_cur, int target, string& prev, vector<string>& ans) {
      char last_op = prev.empty() ? ' ' : prev.back();
      if (nums.length() == 1 || nums[0] != '0') { //except leading zero
        long long num = stol(nums);
        long long tmp = cur, mul_tmp = mul_cur;
        eval(cur, last_op, num, tmp, mul_tmp);
        //cout << prev  << nums << " == " << tmp << " #" << cur << " " << mul_cur << " " << target << endl; //use python eval to test
        if (tmp == target) ans.push_back(prev + nums);
      }
      const size_t nums_len = nums.length();
      if (nums.length() < 2) return;
      
      const size_t cur_prev_len = prev.length();
      for (size_t i = 1; i < nums_len; i++) {
        string fronts = nums.substr(0, i);
        if (i > 1 && nums[0] == '0') break;//leading zero
        string backs = nums.substr(i);
        long long front = stol(fronts);
        long long new_cur = cur, new_mul = mul_cur;
        eval(cur, last_op, front, new_cur, new_mul);
        
        prev += fronts;
        prev.push_back('+');
        foo(backs, new_cur, 0, target, prev, ans);
        
        prev.back() = '-';
        foo(backs, new_cur, 0, target, prev, ans);
        
        prev.back() = '*';
        if (last_op != '*') //last_op is not '*'
          new_mul = ((last_op == '-') * -2 + 1) * front;
        foo(backs, cur, new_mul, target, prev, ans);
        
        prev.resize(cur_prev_len);
      }
    }
};