int SubarraySumB(vector<int> &A,int B) {
    unordered_map<int, int> um;
    int n=A.size();
    int sum = 0, maxLen = -1;
    for (int i = 0; i < n; i++) {
        sum += A[i];
        if (sum == B)
            maxLen = i + 1;
        if (um.find(sum) == um.end())
            um[sum] = i;
        if (um.find(sum - B) != um.end()) {
            if (maxLen < (i - um[sum - B]))
                maxLen = i - um[sum - B];
        }
    }
    return maxLen;
}

int Solution::solve(vector<int> &A, int B) {
    return SubarraySumB(A,B);
    
}