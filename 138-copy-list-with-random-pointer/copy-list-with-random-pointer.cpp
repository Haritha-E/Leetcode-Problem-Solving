/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
      Node *th = head;
      while(th != NULL)
      {
        Node * nn = new Node(th -> val);
        nn->next = th->next;
        th->next = nn;
        th = nn->next;
      }
      th = head;
      while(th != NULL)
      {
        th->next->random = th->random ? th->random->next : NULL;
        th=th->next->next;
      }
      Node* th2=head;
      Node* ans=head->next;
      Node* th3=head->next;
      while(th2){
        th2->next=th3->next;
        th3->next=th2->next?th2->next->next:NULL;
        th2=th2->next;
        th3=th3->next;
      }
      return ans;
    }
};