/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode * head = NULL, * tail = NULL;
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;
    
    if(list1 -> val < list2 ->val)
    {
      head = tail = list1;
      list1 = list1 -> next;
    }
    else
    {
      head = tail = list2;
      list2 = list2 -> next;
    }
    while(list1 && list2)
    {
      if(list1 -> val < list2 ->val)
      {
        tail = tail -> next = list1;
        list1 = list1 -> next;
      }
      else
      {
        tail = tail -> next = list2;
        list2 = list2 -> next;
      }
    }
    if(list2 == NULL) tail -> next = list1;
    if(list1 == NULL) tail -> next = list2;
    return head;
}