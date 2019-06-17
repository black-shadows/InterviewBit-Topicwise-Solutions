bool comparator(int a, int b)
{
    return (a<b);
}

int GetMaxSumAfterNegate(vector<int>& arr, int k)
{
    sort(arr.begin(), arr.end(), comparator);
    int sum = 0;
    int min_value = INT_MAX;
    for(auto& x : arr) {
        if (k > 0 && x < 0 ) {
            x = -x;
            k--;
        }
        min_value = min(min_value,x);
        sum+=x;
    }
    if (k >0) {
        k = k%2;
    }
    if(k>0) {
        sum = sum-(2*min_value);
    }
    return sum;
}

int Solution::solve(vector<int> &A, int B) 
{
    
    return GetMaxSumAfterNegate(A, B);
    
}
