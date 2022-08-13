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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        queue<ListNode*> q;
        stack<ListNode*> s;
        ListNode *cur = head;
        int cnt;
        ListNode *tmp1, *tmp2;
        while (cur != nullptr) {
          q = queue<ListNode*>();
          s = stack<ListNode*>();
          for (cnt = k; cnt > 0 && cur != nullptr; cnt--) {
              q.push(cur);
              s.push(cur);
              cur = cur->next;
          }
          if (q.size() == k) {
              for (cnt = (k>>1); cnt > 0; cnt--) {
                tmp1 = q.front(); q.pop();
                tmp2 = s.top(); s.pop();
                swap(tmp1->val, tmp2->val);
              }
          }
        }
        return head;
    }
};