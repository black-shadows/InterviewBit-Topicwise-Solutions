int Solution::solve(string str) 
{
    
    int n = str.length(); 
  
    // Empty string 
    if (n == 0) 
        return false; 
  
    // If there is single digit 
    if (n == 1) 
        return ((str[0]-'0')%8 == 0); 
  
    // If there is double digit 
    if (n == 2) 
        return (((str[n-2]-'0')*10 + (str[n-1]-'0'))%8 == 0); 
  
    // If number formed by last three digits is 
    // divisible by 8. 
    int last = str[n-1] - '0'; 
    int second_last = str[n-2] - '0'; 
    int third_last = str[n-3] - '0'; 
  
    return ((third_last*100 + second_last*10 + last) % 8 == 0);
    
}
