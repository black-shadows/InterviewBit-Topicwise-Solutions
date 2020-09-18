ListNode* Solution::solve(ListNode* A) {
    ListNode* p=A;
    vector<int>ev,od;
    int count=0;
    while(p!=NULL)
    {
        if(count%2!=0)
        ev.push_back(p->val);
        else 
        od.push_back(p->val);
        count++;
        p=p->next;
    }
    reverse(ev.begin(),ev.end());
    int i=0,p1=0,p2=0;
    p=A;
    while(p!=NULL)
    {
        if(i%2!=0)
        {
            p->val=ev[p1];
            p1++;
        }
        else 
        {
            p->val=od[p2];
            p2++;
        }
            p=p->next;
            i++;
    }
    return A;
}