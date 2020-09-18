int Solution::solve(ListNode* A, int B) {
    if(!A)
    return -1;
    ListNode* f = A, *s = A, *mid = NULL;
    int k = 0;
    while(f && f->next)
    {
        k++;
        s = s->next;
        f = f->next->next;
    }
    if(B > k)
    return -1;
    mid = s;
    f = A, s = A;
    for(int i = 0; i < B; i++)
    {
        f = f->next;
    }
    while(f != mid)
    {
        s = s->next;
        f = f->next;
    }
    return s->val;
}
