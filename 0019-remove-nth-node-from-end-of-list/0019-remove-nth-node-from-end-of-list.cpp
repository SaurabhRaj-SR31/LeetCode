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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        for(int i=1;i<=n;i++)temp=temp->next;
        if(temp==NULL)return head->next;
        ListNode* p2=head;
        while(temp!=NULL && temp->next ){
            temp=temp->next;
            p2=p2->next;
        }
        p2->next=p2->next->next;
        return head;
    }
};