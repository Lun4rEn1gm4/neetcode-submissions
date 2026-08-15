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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode *prev=head , *curr=head->next , *temp=head->next->next;
        ListNode *newHead=nullptr;
        if(temp==nullptr){
            head->next->next=head;
            newHead = head->next;
            head->next=nullptr;
            return newHead;
        }
        while(newHead==nullptr){
            curr->next = prev;
            prev=curr;
            curr=temp;
            if(temp->next == nullptr){
                newHead = temp;
                curr->next = prev;
            }
            else
                temp=temp->next;
        }
        head->next=nullptr;
        return newHead;
    }
};
