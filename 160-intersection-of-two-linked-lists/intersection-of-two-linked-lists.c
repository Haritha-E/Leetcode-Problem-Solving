/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int length(struct ListNode *l){
    int c=0;
    while(l!=NULL){
        c++;
        l=l->next;
    }
    return c;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int l1=length(headA);
    int l2=length(headB);
    while(l1 > l2){
        headA=headA->next;
        l1--;
    }
    while(l2 > l1){
        headB=headB->next;
        l2--;
    }
    while(headA!=headB){
        headA=headA->next;
        headB=headB->next;
    }
    return headA;
}