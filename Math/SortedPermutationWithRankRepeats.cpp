#define MOD 1000003
vector<long long int> getNumSmallest(long long int ind,string &str)
{
    vector<long long int> toreturn;
 long long int count = 0;
 vector<int> hash(256,-1);
 for(long long int i=ind+1;i<str.length();i++)
 {
  if(str[ind]>str[i] && hash[str[i]]==-1)
  {
      toreturn.push_back(str[i]);
      hash[str[i]] = 1;
      count++;
  }
 }
 return toreturn;;
}

long long int pow_mod(long long int a,long long int b)
{
    if(a == 1)
    return 1;
    long long int x =1 ,y = a;
    while(b>0)
    {
        if(b%2)
        {
            x = (x*y)%MOD;
        }
        y = (y*y)%MOD;
        b = b>>1;
    }
    return x;
}

long long int getVal(long long int ind,string &str,vector<long long int> &fact)
{
    vector<long long int> dist = getNumSmallest(ind,str);
    vector<long long int> hash(256,0);
    for(long long int i=ind;i<str.length();i++)
    {
        hash[str[i]]++;
    }
    long long int anS = 0;
    for(int i=0;i<dist.size();i++)
    {
        hash[dist[i]]--;
        long long int ans = fact[str.length()-ind-1];
        for(int i=0;i<256;i++)
        {
            ans = (ans*pow_mod(fact[hash[i]],MOD-2))%MOD;
        }
        anS = (anS+ans)%MOD;
        hash[dist[i]]++;
    }
    return anS;
}

int sortedPermutationRank(string &str)
{
 
 long long int n = str.length();
 vector<long long int> fact(100005,1);
 for(long long int i=1;i<=n;i++)
 fact[i] = (fact[i-1]*i)%MOD;
 
 long long int rank = 0;
 for(long long int i=0;i<n;i++)
 {
  rank = (rank + (getVal(i,str,fact))%MOD)%MOD;
 }
 return (int)rank; 
}

int Solution::findRank(string A) {
    int temp = sortedPermutationRank(A);
    return (temp+1)%MOD;
}