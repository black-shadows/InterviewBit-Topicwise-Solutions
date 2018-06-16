int Solution::divide(int dividend, int divisor) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    long long int dividenD=dividend;
    long long int divisoR = divisor;
    
    
    bool divid = 0,divis=0;
    if(dividenD<0)
    {
        divid = 1;
        dividenD = -dividenD;
    }
    
    if(divisoR<0)
    {
        divis = 1;
        divisoR = -divisoR;
    }
    //cout<<dividenD<<" "<<divisoR<<endl;
    if(divisoR == 1)
    {
        long long int result = dividenD;
        
        if(divis^divid)
        {
            result = -dividenD;
        }
        if(result>INT_MAX)
        {
            return INT_MAX;
        }
        
        return result;
    }
    
    int count=0;
    while(dividenD > 0)
    {
        if(dividenD>divisoR)
        {
            dividenD -=divisoR;
            count++;
        }
        else
        {
            break;
        }
    }
    if(divis^divid)
    {
        return -count;
    }
    return count;
}

