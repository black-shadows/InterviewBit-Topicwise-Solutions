#define MAX 256 

bool compare(char arr1[], char arr2[]) 
{ 
    for (int i=0; i<MAX; i++) 
        if (arr1[i] != arr2[i]) 
            return false; 
    return true; 
} 

vector<int> Solution::solve(string txt, string pat) 
{
    
    vector<int> ans;
    
    int M = pat.length(), N = txt.length(); 
  
    // countP[]:  Store count of all characters of pattern 
    // countTW[]: Store count of current window of text 
    char countP[MAX] = {0}, countTW[MAX] = {0}; 
    for (int i = 0; i < M; i++) 
    { 
        (countP[pat[i]])++; 
        (countTW[txt[i]])++; 
    } 
  
    // Traverse through remaining characters of pattern 
    for (int i = M; i < N; i++) 
    { 
        // Compare counts of current window of text with 
        // counts of pattern[] 
        if (compare(countP, countTW)) 
            ans.push_back(i - M); 
  
        // Add current character to current window 
        (countTW[txt[i]])++; 
  
        // Remove the first character of previous window 
        countTW[txt[i-M]]--; 
    } 
  
    // Check for the last window in text 
    if (compare(countP, countTW)) 
        ans.push_back(N - M);
        
    return ans;
    
}
