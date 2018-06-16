vector<vector<int> > v;
vector<int>vv;
map<vector<int>,int > mm;
int b;
void do_it(int ind,vector<int>vc,int curr)
{
    
    
    
    if(ind>=vv.size())
    
    {
        return ;
    }
    if(curr==b)
    {
        if(mm.find(vc)==mm.end())
        {
            v.push_back(vc);
        }
        mm[vc]++;
        return;
    }
    if(curr>b)
    {
        return ;
    }
    
    
    vc.push_back(vv[ind]);
    do_it(ind,vc,curr+vv[ind]);
    vc.pop_back();
    do_it(ind+1,vc,curr);
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    v.clear();
    vv.clear();
    mm.clear();
    vv=A;
    sort(vv.begin(),vv.end());
    b=B;
    vector<int>vc;
    vc.clear();
    do_it(0,vc,0);
    return v;
}