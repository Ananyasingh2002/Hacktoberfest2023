// Simple code to find the loop in a liskedlist

class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*,int> m;
        ListNode* ptr=head;
        
        while(ptr!=NULL)
        {
            if(m.find(ptr)!=m.end())
            {
                return true;
            }
            m[ptr]++;
            ptr=ptr->next;
        }
        return false;
    }
};
