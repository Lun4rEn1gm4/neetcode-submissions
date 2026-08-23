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
    ListNode* newHead;

   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) return head;

        int cnt = 0;
        ListNode* curr = head;

        while (curr != nullptr) {
            cnt++;
            curr = curr->next;
        }

        int reps = cnt / k;

        ListNode* newHead = head;
        ListNode* prevGroupTail = nullptr;
        curr = head;

        for (int r = 0; r < reps; r++) {
            ListNode* groupHead = curr;
            ListNode* prev = nullptr;

            for (int i = 0; i < k; i++) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            if (prevGroupTail != nullptr)
                prevGroupTail->next = prev;
            else
                newHead = prev;

            groupHead->next = curr;
            prevGroupTail = groupHead;
        }

        return newHead;
    }
};
