/*
check area
*/
typedef size_t point;
typedef vector<point> line;
#define X(p) (points[(p)][0])
#define Y(p) (points[(p)][1])
#define to_point(p) (make_pair((p)[0], (p)[1]))
static inline bool on_line(line& l, point& p, vector<vector<int>>& points) {
  //Parallelogram area
  //AB→=(a, b)、 AC→=(c, d)
  //area = ad−bc
  return (X(p) - X(l[0])) * (Y(p) - Y(l[1])) == (X(p) - X(l[1])) * (Y(p) - Y(l[0]));
}
class Solution {
  public:
    int maxPoints(vector<vector<int>>& points) {
      const size_t len = points.size();
      if (len < 3) return len;
      vector<line> lines(1, line({0,1}));
      //add new point to current graph(lines)
      for (size_t i = 2; i < len; i++) {
        vector<bool> connected(i+1, false);
        for (line& li : lines) {
          if (on_line(li, i, points)) {
            //push point to current line
            li.push_back(i);
            for (point& lp : li) {
              connected[lp] = true;
            }
          } 
        }
        for (size_t j = 0; j < i; j++) {
          if (!connected[j])
            lines.push_back(line({i, j}));
        }
      }
      int ans = 0;
      for (line& li : lines)
        ans = max(ans, (int)li.size());
      return ans;
    }
};