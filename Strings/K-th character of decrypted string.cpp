string Solution::solve(string str, int k) 
{
    
    
    int i, j; 
  
    int n = str.length(); 
  
    // To store length of substring 
    int len; 
  
    // To store length of substring when 
    // it is repeated 
    int num; 
  
    // To store frequency of substring 
    int freq; 
    
    string ans;
  
    i = 0; 
  
    while (i < n) { 
        j = i; 
        len = 0; 
        freq = 0; 
  
        // Find length of substring by 
        // traversing the string until  
        // no digit is found. 
        while (j < n && isalpha(str[j])) { 
            j++; 
            len++; 
        } 
  
        // Find frequency of preceding substring. 
        while (j < n && isdigit(str[j])) { 
            freq = freq * 10 + (str[j] - '0'); 
            j++; 
        } 
  
        // Find length of substring when 
        // it is repeated. 
        num = freq * len; 
  
        // If length of repeated substring is less than 
        // k then required character is present in next 
        // substring. Subtract length of repeated 
        // substring from k to keep account of number of 
        // characters required to be visited. 
        if (k > num) { 
            k -= num; 
            i = j; 
        } 
  
        // If length of repeated substring is 
        // more or equal to k then required  
        // character lies in current substring. 
        else { 
            k--; 
            k %= len; 
            ans.push_back(str[i + k]);
            return ans; 
        } 
    } 
  
    // This is for the case when there 
    // are no repetition in string. 
    // e.g. str="abced". 
    ans.push_back(str[k - 1]);
    return ans; 
    
}
