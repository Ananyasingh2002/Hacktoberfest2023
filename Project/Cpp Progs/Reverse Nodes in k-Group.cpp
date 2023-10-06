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
    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        auto newHead = reverse(head->next);
        auto ptr = newHead;
        while(ptr->next) ptr = ptr->next;
        ptr->next = head;
        head->next = NULL;
        return newHead;
    }
    ListNode* reverseKGroup(ListNode* head, int k){
        if(head == NULL) return head;
        ListNode* ptr = head;
        ListNode* pre = NULL;
        int i = 0;
        while(i<k && ptr){
            pre = ptr;
            ptr = ptr->next;
            i++;
        }
        if(i!=k) return head;
        ListNode* newHead = reverseKGroup(ptr,k);
        pre->next = NULL;
        ListNode* addHead = reverse(head);
        ListNode* temp = addHead;
        while(temp->next) temp = temp->next;
        temp->next = newHead;
        return addHead;
    }
};
