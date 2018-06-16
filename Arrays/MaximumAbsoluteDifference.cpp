int Solution::maxArr(vector<int> &A) {
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN, max4 = INT_MIN;
    assert(!A.empty());
    int ans = INT_MIN;
    int size = A.size();
    for (auto i = 0; i<size; ++i)
    {
        max1 = max(max1, A[i] + i);
        max2 = max(max2, -A[i] + i);
        max3 = max(max3, A[i] - i);
        max4 = max(max4, -A[i] - i);
    }
    for (auto i = 0; i<size; ++i)
    {
        ans = max(ans, max1 - A[i] - i);
        ans = max(ans, max2 + A[i] - i);
        ans = max(ans, max3 - A[i] + i);
        ans = max(ans, max4 + A[i] + i);
    }
    return ans;
}