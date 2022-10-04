class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      
       if (!head)
        return nullptr;

    ListNode new_head(-1);
    new_head.next = head;

    ListNode *slow = &new_head, *fast = &new_head;

    for (int i = 0; i < n; i++)
        fast = fast->next;

    while (fast->next) 
    {
        fast = fast->next;
        slow = slow->next;
    }

    ListNode *to_be_deleted = slow->next;
    slow->next = slow->next->next;
    
    delete to_be_deleted;

    return new_head.next;
    }
};
