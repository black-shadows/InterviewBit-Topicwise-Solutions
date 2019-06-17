int Solution::solve(int A, int B, int C, int D, int E, int F, int G, int H) 
{
    
    // If one rectangle is on left side of other 
    if (A >= G || E >= C) 
        return false; 
  
    // If one rectangle is above other 
    if (B >= H || F >= D) 
        return false; 
  
    return true; 
    
}
