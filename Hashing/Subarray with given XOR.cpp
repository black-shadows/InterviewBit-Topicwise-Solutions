int Solution::solve(vector<int> &a, int k) {
    int n = a.size();
    unordered_map<int, int> map;
    map.reserve(n);
    int temp, ans = 0, xorpre = a[0];
    if(a[0] == k)
        ans = 1;
    map[a[0]] = 1;
    for(int i=1; i<n; i++){
        xorpre ^= a[i];
        if(map.find(xorpre^k) != map.end())
            ans += map[xorpre^k];
        if(xorpre == k)
            ans++;
        map[xorpre]++;
    }
    return ans;
}