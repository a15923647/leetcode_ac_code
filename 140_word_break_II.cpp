//source: https://leetcode.com/problems/word-break-ii/discuss/44178/11ms-C%2B%2B-solution-(concise)
class Solution {
  public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
      unordered_set<string> wmap;
      for (auto e : wordDict) 
        wmap.insert(e);
      return word_break(s, wmap);
    }
    vector<string> word_break(string& s, unordered_set<string>& wordDict) {
      if (m.count(s)) return m[s];
      vector<string> result;
      if (wordDict.count(s)) {
        result.push_back(s);
      }
      //arbitarily cut s into two substring
      for (int i = 1; i < s.size()-1; i++) {
        string word = s.substr(i);
        //if a word is found
        if (wordDict.count(word)) {
          //cut word out from s, so that s = rem || word
          string rem = s.substr(0, i);
          //combine word with the answer of remaining part back to form a subset of result
          vector<string> prev = combine(word, word_break(rem, wordDict));
          //push back all result from prev
          result.insert(result.end(), prev.begin(), prev.end());
        }
      }
      return m[s] = result;
    }
    vector<string> combine(string word, vector<string> prev) {
      for (auto& s : prev) {
        s += " " + word;
      }
      return prev;
    }
    unordered_map<string, vector<string>> m;
};