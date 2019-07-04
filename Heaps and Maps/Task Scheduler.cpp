int Solution::solve(string A, int B) {
    unordered_map<char, int> record;
    int max_freq = 0;
    int max_tasks = 0;
    for(auto a : A) {
        record[a]++;
        max_freq = max(max_freq, record[a]);
    }
    for (auto task : record)
        if (task.second == max_freq)
            max_tasks++;
    int ans = (max_freq - 1) * (B+1) + max_tasks;
    return ans > A.size() ? ans : A.size();
}