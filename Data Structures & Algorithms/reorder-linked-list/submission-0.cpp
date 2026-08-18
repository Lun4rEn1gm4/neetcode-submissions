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
    void reorderList(ListNode* head) {
        ListNode *l1 = head, *ptr2 = head;
        while (ptr2 != nullptr && ptr2->next != nullptr) {
            l1 = l1->next;
            ptr2 = ptr2->next->next;
        }
        ListNode *h2 = l1->next;
        l1->next = nullptr;
        ListNode *curr = h2, *prev = nullptr;
        while (curr != nullptr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        ListNode *t1 = head, *t2 = prev;
        while (t1 != nullptr && t2 != nullptr) {
            ListNode* n1 = t1->next;
            ListNode* n2 = t2->next;
            t1->next = t2;
            t2->next = n1;
            t1 = n1;
            t2 = n2;
        }
    }
};
