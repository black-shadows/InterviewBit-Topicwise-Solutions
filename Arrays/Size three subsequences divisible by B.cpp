int mod = 1000000007;

int countSubSeq(vector<int> A, int N, int M) 
{ 
    int ans = 0; 
  
    // Storing frequencies of all remainders 
    // when divided by M. 
    int h[M];
    
    memset(h, 0, sizeof(h));
    
    for (int i = 0; i < N; i++) { 
        A[i] = A[i] % M; 
        h[A[i]]++; 
    } 
  
    for (int i = 0; i < M; i++) { 
        for (int j = i; j < M; j++) { 
  
            // including i and j in the sum rem 
            // calculate the remainder required  
            // to make the sum divisible by M 
            int rem = (M - (i + j) % M) % M; 
  
            // if the required number is less than 
            // j, we skip as we have already calculated  
            // for that value before. As j here starts  
            // with i and rem is less than j. 
            if (rem < j) 
                continue; 
  
            // if satisfies the first case. 
            if (i == j && rem == j) 
                ans = (ans%mod + h[i] * (h[i] - 1) * (h[i] - 2) / 6)%mod; 
  
            // if satisfies the second case 
            else if (i == j) 
                ans = (ans%mod + h[i] * (h[i] - 1) * h[rem] / 2)%mod; 
  
            else if (i == rem) 
                ans = (ans%mod + h[i] * (h[i] - 1) * h[j] / 2)%mod; 
            else if (rem == j) 
                ans = (ans%mod + h[j] * (h[j] - 1) * h[i] / 2)%mod; 
  
            // if satisfies the third case 
            else
                ans = (ans%mod + h[i] * h[j] * h[rem])%mod; 
        } 
    } 
    return ans%mod; 
} 
  


int Solution::solve(vector<int> &A, int B) 
{
    
    return countSubSeq(A, A.size(), B);
    
}
