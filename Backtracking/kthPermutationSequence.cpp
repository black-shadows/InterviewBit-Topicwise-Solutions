string Solution::getPermutation(int n, int k) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    string toreturn = "" ;
    vector<int> vec;
    for(int i=1;i<=n;i++)
    {
        vec.push_back(i);
    }
    
    vector<long long int> fact(n+1,0);
    fact[0] = 1;
    
    for(long long int i=1;i<=n;i++)
    {
        fact[i] = min((i*fact[i-1]),(long long int)INT_MAX);
    }
    
    if(k>fact[n] || n==0)
    return "";
    
    k--;
    while(vec.size()!=0)
    {
        int N = vec.size();
        int pos = k/fact[N-1];
        k = k%fact[N-1];
        toreturn += (to_string(vec[pos]));
        vec.erase(vec.begin()+pos);
    }
    return toreturn;
}