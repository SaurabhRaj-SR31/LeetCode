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
        if(list1==NULL)return list2;
        if(list2==NULL)return list1;
        if(list1->val <= list2->val)
        {
            list1->next=mergeTwoLists(list1->next,list2);
            return list1;
        }
        else{
            list2->next=mergeTwoLists(list1,list2->next);
            return list2;
        }}

    
    ListNode* partiton(int s,int e,vector<ListNode*>& lists){
        if(s==e)return lists[s];
        int mid=s+(e-s)/2;
         ListNode* l1=partiton(s,mid,lists);
         ListNode* l2=partiton(mid+1,e,lists);
        return mergeTwoLists(l1,l2);

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int s=0;
        int e=lists.size()-1;
        if(lists.size()==0)return NULL;
        return partiton(s,e,lists);
        

    }
};