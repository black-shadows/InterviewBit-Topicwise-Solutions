int Solution::solve(vector<int>& nums)
{
    int s = nums.empty() ? 0 : *max_element(nums.begin(), nums.end());
    vector<int> sieve(s + 1, 1), numsMap(s + 1, 0);
    for (int n : nums) {
        numsMap[n] = 1;
    }
    int primeDivisorsCount = 0;
    for (int i = 2; i <= s; i++) {
        if (!sieve[i]) {
            continue;
        }
        bool isPresent = numsMap[i];
        for (int j = 2 * i; j <= s; j += i) {
            sieve[j] = 0;
            isPresent |= numsMap[j];
        }
        primeDivisorsCount += (isPresent) ? 1 : 0;
    }
    return primeDivisorsCount;
}