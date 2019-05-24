long long distanceToNearestSquare(long long n)
{
    auto nSqrt = static_cast<long long>(sqrtl(n));
    auto below = nSqrt * nSqrt;
    auto above = (nSqrt + 1) * (nSqrt + 1);
    return min(n - below, above - n);
}

int getSum(vector<long long>& BITree, int index)
{
    int sum = 0;
    while (index > 0) {
        sum += BITree[index];
        index -= (index & (-index));
    }
    return sum;
}

void updateBIT(vector<long long>& BITree, int index, long long val)
{
    while (index < BITree.size()) {
        BITree[index] += val;
        index += (index & (-index));
    }
}

int Solution::solve(vector<int>& numbers, vector<vector<int>>& queries)
{
    int n = numbers.size();
    vector<long long> BITree(n + 1, 0);
    for (int i = 0; i < n; i++) {
        numbers[i] = distanceToNearestSquare(numbers[i]);
        updateBIT(BITree, i + 1, numbers[i]);
    }

    long long sum = 0;
    for (auto& query : queries) {
        if (query[0] == 1) {
            long long newVal = distanceToNearestSquare(query[2]);
            updateBIT(BITree, query[1], newVal - numbers[query[1] - 1]);
            numbers[query[1] - 1] = newVal;
        } else {
            auto L = getSum(BITree, query[1] - 1);
            auto R = getSum(BITree, query[2]);
            sum += R - L;
            sum %= 1000000007;
        }
    }
    return static_cast<int>(sum);
}