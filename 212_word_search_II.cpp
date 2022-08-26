class TrieNode {
  public:
    TrieNode() {
      is_end = false;
      word_cnt = 1;
      memset(children, 0, 26 * sizeof(TrieNode*));
    }
    bool is_end;
    size_t word_cnt;
    TrieNode *children[26];
};

class Trie {
  public:
    Trie(vector<string>& words) {
      root = new TrieNode();
      for (string& word : words) {
        addWord(word);
      }
    }
    void addWord(string& word) {
      TrieNode *cur = root;
      size_t idx;
      for (const char c : word) {
        idx = c - 'a';
        if (cur->children[idx] == NULL) {
          cur->children[idx] = new TrieNode();
        }
        cur->word_cnt++;
        cur = cur->children[idx];
      }
      cur->is_end = true;
    }
    void deleteWord(string& word) {
      _dw(word, 0, &root);
    }
    TrieNode *getRoot() {return root;}
  private:
    TrieNode *root;
    void _dw(string& word, size_t i, TrieNode **cur) {
      if (i == word.length()) {
        (*cur)->is_end = false;
      } else {
        _dw(word, i+1, &((*cur)->children[word[i] - 'a']));
      }
      if (--(*cur)->word_cnt == 0) {
        /*
        delete *cur;
        *cur = NULL;
        */
        TrieNode *tmp = *cur;
        *cur = NULL;
        delete *cur;
      }
      
    }
};

class Solution {
  public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
      Trie trie(words);
      TrieNode *root = trie.getRoot();
      const size_t xb = board.size();
      const size_t yb = board[0].size();
      vector<string> ans;
      string word;
      for (size_t x = 0; x < xb; x++)
        for (size_t y = 0; y < yb; y++)
          findWord(board, x, y, xb, yb, root, word, ans, trie);
      return ans;
    }
    void findWord(vector<vector<char>>& board, 
                  int x, 
                  int y,
                  size_t xb,
                  size_t yb,
                  TrieNode *cur, 
                  string& word, 
                  vector<string>& ans, 
                  Trie& trie) {
      if (x < 0 || x >= xb || y < 0 || y >= yb || board[x][y] == ' ') return;
      const char bc = board[x][y];
      const size_t idx = bc - 'a';
      if (cur->children[idx]) {
        //track
        word += bc;
        board[x][y] = ' ';
        
        cur = cur->children[idx];
        if (cur->is_end) {
          ans.push_back(word);
          trie.deleteWord(word);
        }
        //turns to one of four directions
        findWord(board, x-1, y, xb, yb, cur, word, ans, trie);
        findWord(board, x+1, y, xb, yb, cur, word, ans, trie);
        findWord(board, x, y-1, xb, yb, cur, word, ans, trie);
        findWord(board, x, y+1, xb, yb, cur, word, ans, trie);
        //backtrack
        word.pop_back();
        board[x][y] = bc;
      }
    }
};

