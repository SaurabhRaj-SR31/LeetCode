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
    bool iscritical(int x,int y,int z){
        return ((x>y&&y<z)||(x<y&&y>z));
    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans(2,-1);
        int prev_pos=-1;
        int pos=0;
        int p1=-1;
        int p2=-1;
        int prev_val=head->val;
        head=head->next;
        int mini=1e9;
        while(head->next!=NULL){
            if(iscritical(prev_val,head->val,head->next->val)){
                if(p1==-1){
                    p1=pos;
                }else{
                    mini=min(mini,pos-prev_pos);

                }
                p2=pos;
                prev_pos=pos;
            }
            pos++;
             prev_val=head->val;
        head=head->next;


        }
        int maxi=p2-p1;
        if(p1==-1 ||p1==p2)return ans;
        else{
            ans[1]=maxi;
            ans[0]=mini;
            return ans;
        }
    }
};