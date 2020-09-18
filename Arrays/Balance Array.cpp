int Solution::solve(vector<int> &A) {
    int left_odd = 0;
    int left_even = 0;
    int right_odd = 0;
    int right_even = 0;
    for(int i = 0; i < A.size(); ++i)
    {
        if( i % 2 == 0)
        {
            right_even += A[i];
        }
        else
        {
            right_odd += A[i];
        }
    }
    int count = 0;
    for(int i = 0; i < A.size(); ++i)
    {
        if(i % 2 == 0)
        {
            right_even -= A[i];
            if(left_odd + right_even == left_even + right_odd)
            {
                ++count;
            }
            left_even += A[i];
        }
        else
        {
            right_odd -= A[i];
            if(left_odd + right_even == left_even + right_odd)
            {
                ++count;
            }
            left_odd += A[i];
        }
    }
    return count;
}