int Solution::solve(vector<int> &A, int B) {

    int count = 0;
    int gap = 0;
    int r = 0;
    int l = 0;
    
    while(r < A.size())
    {
        if(A[r] == 0)
        {
            count++;
        }
        if(count > B)
        {
            if(A[l] == 0)
            {
                count--;
            }
            l++;
        }
        if(count <= B)
        {
            if(r-l > gap)
            {
                gap = r-l;
            }
        }
        r++;
    }
    return gap+1;
}