int Solution::hammingDistance(const vector<int> &nums) {
    long long int res=0, size=nums.size();
    for(int i=0,ones ; i<31 ; ++i){
        ones=0;
        for(int j=0 ; j<size ; ++j){
            if(nums[j] & (1<<i))    ++ones;
        }
        res += 2LL*ones*(size-ones);
        res %= 1000000007;
    }
    int reis = res;
    return reis;
}