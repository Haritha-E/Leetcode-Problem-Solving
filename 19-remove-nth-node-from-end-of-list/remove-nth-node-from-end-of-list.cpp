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
        int c=0;
        ListNode* nn=head;
        while(nn!=NULL){
            c++;
            nn=nn->next;
        }
        if(c==1)
            return NULL;
        int i=c-n,j=1;
        nn=head;
        if(i==0){
            ListNode* p=head;
            head=p->next;
            delete p;
            return head;
        }
        while(j<i){
            nn=nn->next;
            j++;
        }
        ListNode* p=nn->next;
        nn->next=p->next;
        delete p;
        return head;
    }
};