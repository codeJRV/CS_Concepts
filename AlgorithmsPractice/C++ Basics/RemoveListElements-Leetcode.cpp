class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
    ListNode** tmp = &head;          // double pointer temp = address of head
    while(*tmp){
        if((*tmp)->val == val) *tmp = (*tmp)->next;
        else tmp = &((*tmp)->next);
    }
    return head;
        
    }
};