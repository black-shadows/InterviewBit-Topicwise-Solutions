void solveForResult(vector<int> &toreturn,int A,int curr)
{
    if(curr == A)
    {
        return;
    }
    int ind = toreturn.size()-1;
    for(int i=ind;i>=0;i--)
    {
        toreturn.push_back((1<<curr)+toreturn[i]);
    }
    solveForResult(toreturn,A,curr+1);
}

vector<int> Solution::grayCode(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> toreturn;
    toreturn.push_back(0);
    toreturn.push_back(1);
    solveForResult(toreturn,A,1);
    
    return toreturn;
}
