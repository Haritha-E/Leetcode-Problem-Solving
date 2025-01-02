/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
        int c=0;
        struct ListNode* nn=head;
        while(nn!=NULL){
            c++;
            nn=nn->next;
        }
        if(c==1)
            return NULL;
        int i=c-n,j=1;
        nn=head;
        if(i==0){
            head=nn->next;
            free(nn);
            return head;
        }
        while(j<i){
            nn=nn->next;
            j++;
        }
        struct ListNode* p=nn->next;
        nn->next=p->next;
        free(p);
        return head;
}