int Solution::solve(vector<int> &arr) {

        int res = 0, n = arr.size();
        for (int i = 0; i < n; ++i) {
            int cur = arr[i], j = i + 1;
            for (; j <= cur; ++j) {
                cur = max(cur, arr[j]);
                if (cur >= arr.back()) return res + 1;
            }
            i = j - 1;
            ++res;
        }
        return res;
    
}