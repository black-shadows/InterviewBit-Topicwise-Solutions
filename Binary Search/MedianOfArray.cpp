double getMedian(const vector<int> &A,const vector<int> &B,int m,int n)
{
    int k = (m+n+1)/2;
    int beg = 0;
    int end = m;
    
    while(beg<=end)
    {
        int i = (beg+end)/2;
        int j = k-i;
        
        if((i-1)>=0 &&j<n && A[i-1]>B[j])
        {
            end = i-1;
        }
        else if((j-1)>=0 && i<m && B[j-1]>A[i])
        {
            beg = i+1;
        }
        else
        {
            double max_of_left,min_of_right;
            if(i==0) max_of_left = B[j-1];
            else if(j==0) max_of_left = A[i-1];
            else max_of_left = max(B[j-1],A[i-1]);
            
            if((m+n)%2)
            {
                return max_of_left;
            }
            
            if(i==m) min_of_right = B[j];
            else if(j==n) min_of_right = A[i];
            else min_of_right = min(B[j],A[i]);
            
            return (min_of_right+max_of_left)/2.0;
        }
    }
}

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size()==0)
    {
        if(B.size()%2)
        return B[B.size()/2];
        else
        {
            return (B[B.size()/2-1]+B[B.size()/2])/2.0;
        }
    }
    else if(B.size() == 0)
    {
        if(A.size()%2)
        return A[A.size()/2];
        else
        {
            return (A[A.size()/2-1]+A[A.size()/2])/2.0;
        }
    }
    else
    {
        if(A.size()<B.size())
        {
            return getMedian(A,B,A.size(),B.size());
        }
        else
        {
            return getMedian(B,A,B.size(),A.size());
        }
    }
    return 0.0;
}