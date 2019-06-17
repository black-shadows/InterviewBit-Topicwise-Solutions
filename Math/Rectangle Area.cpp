bool isOverlap(int A, int B, int C, int D, int E, int F, int G, int H)
{
    
    // If one rectangle is on left side of other 
    if (A >= G || E >= C) 
        return false; 
  
    // If one rectangle is above other 
    if (B >= H || F >= D) 
        return false; 
  
    return true; 
    
}

int Solution::solve(int A, int B, int C, int D, int E, int F, int G, int H) 
{
    
    if(isOverlap(A, B, C, D, E, F, G, H))
    {
        
        int areaI = (min(C, G) - max(A, E)) * (min(D, H) - max(B, F)); 
        
        return areaI;
        
    }
    
    else
    {
        
        return 0;
        
    }
    
}
