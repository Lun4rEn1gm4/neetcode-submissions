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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode *c1 = l1, *c2 = l2, *h1 = head;
        int a1 = 0, a2 = 0, carry = 0;
        while (c1 != nullptr || c2 != nullptr || carry!=0) {
            if (c1 == nullptr)
                a1 = 0;
            else {
                a1 = c1->val;
                c1 = c1->next;
            }
            if (c2 == nullptr)
                a2 = 0;
            else {
                a2 = c2->val;
                c2 = c2->next;
            }
            int sum = a1 + a2 + carry;
            carry = 0;
            if (sum >= 10) {
                carry = 1;
                sum -= 10;
            }
            h1->next = new ListNode();
            h1 = h1->next;
            h1->val = sum;
        }
        return head->next;
    }
};
