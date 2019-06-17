int Solution::solve(string s) 
{
    
    int n = s.length();
    
    int p = 0, count = 0, mc = 0;
    
    while(p < n)
    {
        
        if(s[p] == '1')
        {
            
            count = 0;
            
            while(s[p] == '1')
            {
                
                count++;
                
                p++;
                
            }
            
        }
        
        else
        {
            
            p++;
            
        }
        
        mc = max(mc, count);
        
    }
    
    // To count all 1's in the string 
    int cnt_one = 0; 
  
    for (int i = 0; i < n; i++) { 
        if (s[i] == '1') 
            cnt_one++; 
    } 
  
    // To store cumulative 1's 
    int left[n], right[n]; 
  
    if (s[0] == '1') 
        left[0] = 1; 
    else
        left[0] = 0; 
  
    if (s[n - 1] == '1') 
        right[n - 1] = 1; 
    else
        right[n - 1] = 0; 
  
    // Counting cumulative 1's from left 
    for (int i = 1; i < n; i++) { 
        if (s[i] == '1') 
            left[i] = left[i - 1] + 1; 
  
        // If 0 then start new cumulative 
        // one from that i 
        else
            left[i] = 0; 
    } 
  
    for (int i = n - 2; i >= 0; i--) { 
        if (s[i] == '1') 
            right[i] = right[i + 1] + 1; 
  
        else
            right[i] = 0; 
    } 
  
    int cnt = 0, max_cnt = mc; 
  
    for (int i = 1; i < n - 1; i++) { 
        // perform step 3 of the approach 
        if (s[i] == '0') { 
  
            // step 3 
            int sum = left[i - 1] + right[i + 1]; 
  
            if (sum < cnt_one) 
                cnt = sum + 1; 
  
            else
                cnt = sum; 
  
            max_cnt = max(max_cnt, cnt); 
            cnt = 0; 
        } 
    } 
  
    return max_cnt; 
}
