int Solution::solve(vector<int> &A) {
    int N = A.size();
    int arr[100001];
    int arro[100001];
    
    for (int i = 0; i < 100001; i++) 
        arr[i] = 1000000;
        
    for (int i = 0; i < 100001; i++) 
        arro[i] = 1000000;
    
    int z = 0, o = 0, ans = 0;
    
    for (int i = 0; i < N; i++) {
        if (A[i]) o++;
        else z++;
        if (z >= o) {
            arr[z - o] = min(arr[z - o], i);
            int x = z - o + 1;
            if (arr[x] != 1000000) {
                ans = max(ans, i - arr[x]);
            }
        } else if (z < o) {
            if (o - z == 1) {
                ans = max(ans, i + 1);
            } else {
                arro[o - z] = min(arro[o - z], i);
                int x = o - z - 1;
                if (arro[x] != 1000000) {
                    ans = max(ans, i - arro[x]);
                }
            }
        }
    }
    
    return ans;
}
