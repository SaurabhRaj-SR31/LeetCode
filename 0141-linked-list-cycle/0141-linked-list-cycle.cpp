/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
         if(!head || !head->next )return false;
          ListNode *slow=head;
        ListNode *fast=head;

        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)break;
        }
        if(slow!=fast)return false;
        ListNode *p=head;
        while(p!=slow){
            p=p->next;
            slow=slow->next;

        }
        return true;
    }
};