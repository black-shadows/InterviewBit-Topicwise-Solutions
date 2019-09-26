int solveit(vector<int> &A) 
{ 
    int g=A[0],mx=A[0],n=A.size(); 
    
    for(int x:A) 
    { 
        g = __gcd(x,g); 
        
        mx=max(mx,x); 
        
    } 
    
    return (mx/g - n)%2; 
    
}

int Solution::solve(vector<int> &A) 
{
    
    return solveit(A);
    
}
