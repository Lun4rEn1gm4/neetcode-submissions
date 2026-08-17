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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        ListNode *newHead, *cur1, *cur2, *temp, *next;
        if (list1->val < list2->val) {
            newHead = list1;
            cur1 = list1->next;
            cur2 = list2;
        } else {
            newHead = list2;
            cur2 = list2->next;
            cur1 = list1;
        }
        temp = newHead;
        while (1) {
            if (cur1 == nullptr) {
                temp->next = cur2;
                break;
            } else if (cur2 == nullptr) {
                temp->next = cur1;
                break;
            } else {
                if (cur1->val < cur2->val) {
                    next = cur1;
                    cur1 = cur1->next;
                } else {
                    next = cur2;
                    cur2 = cur2->next;
                }
            }
            temp->next = next;
            temp = temp->next;
        }
        return newHead;
    }
};
