
int min(int a,int b)
{
    if(a<b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int sq = sqrt(A.size()-1);
    int num_ranges = ceil((A.size()-1)/(double)sq);
    vector<int> hash(num_ranges+1,0);
    for(int i=0;i<A.size();i++)
    {
        int r_num = ceil(A[i]/(double)sq);
        hash[r_num]++;
    }
    
    
    int i;
    for(i=1;i<hash.size();i++)
    {
        if(hash[i]>sq)
        {
            break;
        }
    }
    int loc = i;
    if(i==hash.size())
    {
        loc = i-1;
    }
    
    hash.clear();
    
    int beg = sq*(loc-1)+1;
    int end = min(sq*(loc),A.size()-1);
    
    vector<int> hash1(sq,0);

    for(int i=0;i<A.size();i++)
    {
        if(A[i]<=end && (A[i]-beg) >= 0)
        {
            hash1[A[i]-beg]++;
        }
    }
    
    for(int i=0;i<hash1.size();i++)
    {
        if(hash1[i]>1)
        {
            return beg+i;
        }
    }

    return 0;
}