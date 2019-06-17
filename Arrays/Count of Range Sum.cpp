int mergeSort(vector<long>& sum, int lower, int upper, int low, int high)
{
    if(high-low <= 1) return 0;
    int mid = (low+high)/2, m = mid, n = mid, count =0;
    count =mergeSort(sum,lower,upper,low,mid) +mergeSort(sum,lower,upper,mid,high);
    for(int i =low; i< mid; i++)
    {
        while(m < high && sum[m] - sum[i] < lower) m++;
        while(n < high && sum[n] - sum[i] <= upper) n++;
        count += n - m;
    }
    inplace_merge(sum.begin()+low, sum.begin()+mid, sum.begin()+high);
    return count;
}

int Solution::solve(vector<int> &nums, int lower, int upper) 
{

    int len = nums.size();
    vector<long> sum(len + 1, 0);
    for(int i =0; i< len; i++) sum[i+1] = sum[i]+nums[i];
    return mergeSort(sum, lower, upper, 0, len+1);
    
}
