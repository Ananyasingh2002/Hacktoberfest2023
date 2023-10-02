/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//Detect Cycle in a Linked List using Slow Fast approach
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode * slow = head;
        ListNode * fast = head;
      
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
          
            if(slow==fast)
                return true;
        }
      
        return false;
    }
};
