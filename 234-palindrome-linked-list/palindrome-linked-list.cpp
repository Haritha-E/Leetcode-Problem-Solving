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
    bool isPalindrome(ListNode* head) {
        vector<int>res;
        struct ListNode* current=head;
        while(current!=NULL){
            res.push_back(current->val);
            current=current->next;
        }
        int left=0,right=res.size()-1;
        while(left<=right){
            if(res[left++]!=res[right--])
                return false;
        }
        return true;
    }
};