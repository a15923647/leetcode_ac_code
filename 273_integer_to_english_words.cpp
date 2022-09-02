const string stringify[20] = {
  "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", 
  "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
};
const string tensStringify[8] = {
  "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
};
string three_digits(int num) {
  string res;
  int tmp;
  //last two digit
  tmp = num % 100;
  //rule out zero
  if (tmp) {
    if (tmp < 20) {
      res = stringify[tmp];
    } else {
      //over or equal to 20
      res = tensStringify[tmp / 10 - 2];
      //rule out zero
      if (tmp % 10) res += " " + stringify[tmp % 10];
    }
  }
  num /= 100;
  //hundred
  tmp = num % 10;
  if (tmp) {
    res = stringify[tmp] + " Hundred" + (res.length() > 0 ? " " + res : "");
  }
  return res;
}
class Solution {
  public:
    string numberToWords(int num) {
      if(num == 0) return stringify[0];
      string res;
      if (num % 1000)
        res = three_digits(num);
      num /= 1000;
      //thousand
      if (num % 1000)
        res = three_digits(num) + " Thousand" + (res.length() > 0 ? " " + res : "");
      num /= 1000;
      //million
      if (num % 1000)
        res = three_digits(num) + " Million" + (res.length() > 0 ? " " + res : "");
      num /= 1000;
      //billion
      if (num % 1000)
        res = three_digits(num) + " Billion" + (res.length() > 0 ? " " + res : "");
      num /= 1000;
      return res;
    }
};