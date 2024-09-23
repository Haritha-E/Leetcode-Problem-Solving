/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(head==NULL){
        return NULL;
    }

    struct ListNode* prev=NULL;
    struct ListNode* current=head;
    struct ListNode* nextnode=head;
    while(nextnode!=NULL){
        nextnode=current->next;
        current->next=prev;
        prev=current;
        current=nextnode;
    }
    return prev;
}