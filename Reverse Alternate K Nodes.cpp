ListNode* Solution::solve(ListNode* A, int B) {
    ListNode* start = A;
    ListNode* end = A;
    int n = 1,c = 1;
    while(start && end){
        stack<int> st;
        n = B;
        if(c % 2 == 1){
            while(n--){
                st.push(end->val);
                end = end->next;
            }
            while(!st.empty()){
                start->val = st.top();
                st.pop();
                start = start->next;
            }
        }
        else{
            while(n--){
                start = start->next;
                end = end->next;
            }
        }
        c++;
    }
    return A;
}