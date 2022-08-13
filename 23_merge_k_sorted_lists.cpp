/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
static inline void insert(ListNode *node, ListNode **target) {
  node->next = (*target);
  (*target) = node;
}

class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const ListNode* lhs, const ListNode* rhs) const
  {
    if (reverse) return (lhs->val>rhs->val);
    else return (lhs->val<rhs->val);
  }
};

class Solution {
  public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      ans = nullptr;
      //merge sort again and again
      priority_queue<ListNode*, vector<ListNode*>, mycomparison> maxh(mycomparison(true));
      for(auto e : lists)
        if (e != nullptr)
          maxh.push(e);
      ListNode *cur_min_ptr;
      ListNode **tail = &ans;
      while (!maxh.empty()) {
        cur_min_ptr = maxh.top();
        maxh.pop();
        if (cur_min_ptr->next != nullptr) {
          maxh.push(cur_min_ptr->next);
        }
        insert(new ListNode(cur_min_ptr->val), tail);
        
        tail = &((*tail)->next);
      }
      return ans;
    }
    ListNode *ans;
};