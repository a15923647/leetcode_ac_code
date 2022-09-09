//https://leetcode.com/problems/self-crossing/discuss/79131/Java-Oms-with-explanation
class Solution {
  public:
    bool isSelfCrossing(vector<int>& dist) {
      const size_t dis_len = dist.size();
      int dist0, dist1, dist2, dist3, dist4, dist5;
      for (int i = 3; i < dis_len; i++) {
        dist0 = dist[i]; dist1 = dist[i-1]; dist2 = dist[i-2]; dist3 = dist[i-3];
        if (i >= 4) dist4 = dist[i-4];
        if (i >= 5) dist5 = dist[i-5];
        if (
          (dist0 >= dist2 && dist1 <= dist3) || \
          (i >= 4 && dist1 == dist3 && dist0+dist4 >= dist2) || \
          (i >= 5 && dist2 >= dist4 && dist0+dist4 >= dist2 && dist1 <= dist3 && dist1+dist5 >= dist3)
        ) return true;
      }
      return false;
    }
};
