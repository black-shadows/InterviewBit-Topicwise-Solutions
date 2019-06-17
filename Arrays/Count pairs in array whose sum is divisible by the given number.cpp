int mod = 1000000007;

int Solution::solve(vector<int> &a, int k) 
{
   long long int n = a.size();
   long long int m[k];
   for(int i=0; i<k; i++)
       m[i]=0;
    for(int i = 0; i < n; i++){
        m[a[i]%k]++;
    }
    long long int sum=0;
    sum+=(m[0]*(m[0]-1))/2;
     for(int i=1; i<=k/2 && i!=k-i; i++){
         sum+=m[i]*m[k-i];
     }
    if(k%2==0)
        sum+=(m[k/2]*(m[k/2]-1))/2;
    return (sum)%mod;
}
