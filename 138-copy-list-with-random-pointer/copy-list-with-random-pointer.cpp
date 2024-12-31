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
      unordered_map<Node*, Node*>m;
      Node *th = head;
      while(th != NULL)
      {
        Node * newNode = new Node(th -> val);
        m[th] = newNode;
        th = th -> next;
      }
      th = head;
      while(th != NULL)
      {
        m[th] -> next = m[th -> next];
        m[th] -> random = m[th -> random];
        th = th -> next;
      }
      return m[head];
        
    }
};