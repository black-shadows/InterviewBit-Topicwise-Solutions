vector <int> Solution::solve(vector<int> &A)
{
    int n = A.size();
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    vector<int> freq(A[0] + 1, 0);
    for (int i=0;i<n;i++)
    {
        freq[A[i]]++;
    }

    n = sqrt(n);
    vector <int> B(n, 0);
    int x, l = 0;

    for (int i = 0; i < n; i++) {
        if (freq[A[i]] != 0) {

            B[l] = A[i];

            freq[B[l]]--;
            l++;
            for (int j = 0; j < l; j++) {
                if (i != j) {

                    x = __gcd(A[i], B[j]);

                    freq[x] -= 2;
                }
            }
        }
    }
return B;
}