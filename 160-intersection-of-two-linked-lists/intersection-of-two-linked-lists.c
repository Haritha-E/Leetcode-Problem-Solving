/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *th1=headA, *th2=headB;
    while(th1!=th2){
        th1 = th1==NULL ? headB:th1->next;
        th2 = th2==NULL ? headA:th2->next;
    }
    return th1;
}