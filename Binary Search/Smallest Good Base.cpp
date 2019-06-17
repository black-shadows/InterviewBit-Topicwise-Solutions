size_t try_k(size_t n, int k) {
    double ord = 1.0 / (k-1);
    double root = pow(n, ord); //O(log n) for required floating point precission
    size_t a = floor(root);
    if (a < 2) return 0;
    size_t sum = 1;
    for (int i = 0; i < k-1; i++) sum = sum * a + 1;  // k-1 time, which is O(log n)
    if (sum != n) return 0;
    return a;
}

string Solution::solve(string nstr) 
{
    
    size_t n = stoull(nstr);
    for (int k = 63; k >= 3; k--) {
        size_t result = try_k(n, k);
        if (result > 0) return to_string(result);
    }
    return to_string(n-1);
}
