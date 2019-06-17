const int maxn=262144+5;
int num[maxn];

vector<int> Solution::solve(vector<char> &A, vector<string> &B)
{
    
    memset(num,0,sizeof(num));
    
    int t = A.size();
    
    int j = 0;
    
    vector<int> ans;
    
    while(t--)
    {
        long long int num_1 = stoll(B[j]);
        long long int num_2=0;
        for(int i=0;i<18;i++)
        {
            num_2=num_2*2+num_1%2;
            num_1=num_1/10;
        }
        if(A[j]=='+')
            num[num_2]++;
        else if(A[j]=='-')
            num[num_2]--;
        else if(A[j]=='?')
            ans.push_back(num[num_2]);
        
        j++;
        
    }
    
    return ans;
    
}
