ListNode* Solution::solve(ListNode* head) {
    ListNode dummy1(0);
    ListNode* zero = &dummy1;
    ListNode dummy2(0);
    ListNode* one = &dummy2;
    
    while(head){
        if(head->val == 0){
            zero->next = head;
            zero = zero->next;
            head = head->next;
        }
        else if(head->val == 1){
            one->next = head;
            one = one->next;
            head = head->next;
        }
    }
    one->next = NULL;
    zero->next = dummy2.next;
    return dummy1.next;
}