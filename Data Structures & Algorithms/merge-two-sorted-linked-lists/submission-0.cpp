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
        ListNode *cur1=list1 , *cur2=list2;
        ListNode *Dummy = new ListNode(0) , *curr = Dummy;
        while(!(cur1==nullptr&&cur2==nullptr)){
            int curval;
            if(cur1==nullptr||cur2==nullptr){
                if(cur1==nullptr){
                    curval=cur2->val; cur2=cur2->next;
                }else{
                    curval=cur1->val; cur1=cur1->next;
                }
            }
            else if(cur1->val<cur2->val){
                curval=cur1->val; cur1=cur1->next;
            }else{
                curval=cur2->val; cur2=cur2->next;
            }
            curr->next = new ListNode(curval);
            curr=curr->next;
        }
        return Dummy->next;
    }
};
