struct node {
    int val;
    int min;
    int max;
    node(int val, int min, int max) : val(val), min(min), max(max) {};
};

int Solution::solve(vector<int> &A) {
    if(A.empty()) return 1;
    queue<node> q;
    bool left_available = true;
    bool right_available = true;
    node cur_node(A.front(), numeric_limits<int>::min(), numeric_limits<int>::max());
    int i = 1;
    while(i < A.size()) {
        if(cur_node.min <= A[i] && A[i] <= cur_node.max) {
            if(left_available && A[i] < cur_node.val) {
                q.emplace(A[i], cur_node.min, cur_node.val);
                left_available = false;
                i++;
                continue;
            }
            if(right_available && cur_node.val < A[i]) {
                q.emplace(A[i], cur_node.val, cur_node.max);
                left_available = false;
                right_available = false;
                i++;
                continue;
            } else if(q.empty()) return 0;
        } else if(q.empty()) return 0;
        cur_node = q.front();
        q.pop();
        left_available = true;
        right_available = true;
    }
    return 1;
}
