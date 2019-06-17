const int MAX_CHAR = 26; 

string firstnonrepeating(string str) 
{ 
    queue<char> q; 
    string b;
    int charCount[MAX_CHAR] = { 0 }; 
  
    // traverse whole stream 
    for (int i = 0; str[i]; i++) { 
  
        // push each character in queue 
        q.push(str[i]); 
  
        // increment the frequency count 
        charCount[str[i] - 'a']++; 
  
        // check for the non pepeating character 
        while (!q.empty()) { 
            if (charCount[q.front() - 'a'] > 1) 
                q.pop(); 
            else { 
                b.push_back(q.front());
                break; 
            } 
        } 
  
        if (q.empty()) 
            b.push_back('#'); 
    } 
    return b;
} 

string Solution::solve(string A) 
{
    
    return firstnonrepeating(A);
    
}
