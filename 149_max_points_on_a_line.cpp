/*
check area
*/
typedef size_t point;
typedef vector<point> line;//vector<(x, y)>
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
      vector<line> lines;
      lines.push_back(line({0,1}));
      //add new point to current graph(lines)
      for (size_t i = 2; i < len; i++) {
        unordered_set<size_t> connected;
        for (line& li : lines) {
          if (on_line(li, i, points)) {
            //push point to current line
            li.push_back(i);
            for (point& lp : li) {
              connected.insert(lp);
            }
          } 
        }
        for (size_t j = 0; j < i; j++) {
          if (!connected.count(j))
            lines.push_back(line({i, j}));
        }
      }
      int ans = 0;
      for (line& li : lines)
        ans = max(ans, (int)li.size());
      return ans;
    }
};