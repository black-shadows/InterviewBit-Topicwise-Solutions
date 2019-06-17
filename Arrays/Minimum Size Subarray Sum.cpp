int Solution::solve(vector<int> &nums, int s) 
{
    
    int l=0,r=-1,sum=0,res=INT_MAX,len=nums.size();
    if(nums.empty()) return 0;
    while(r<len)
    {
        if(sum>=s)
        {
            res=min(res,r-l+1);
            sum-=nums[l];
            l++;
        }
        else 
        {  
           r++;
           if(r<len) sum+=nums[r];
        }
    }
    if(res==INT_MAX) return 0;
    else return res;
}
