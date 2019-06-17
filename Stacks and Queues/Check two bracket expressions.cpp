const int MAX_CHAR = 26; 
  
// Return local sign of the operand. For example, 
// in the expr a-b-(c), local signs of the operands 
// are +a, -b, +c 
bool adjSign(string s, int i) 
{ 
    if (i == 0) 
        return true; 
    if (s[i - 1] == '-') 
        return false; 
    return true; 
}; 

void eval(string s, vector<int>& v, bool add) 
{ 
    // stack stores the global sign 
    // for operands. 
    stack<bool> stk; 
    stk.push(true); 
  
    // + means true 
    // global sign is positive initially 
  
    int i = 0; 
    while (s[i] != '\0') { 
        if (s[i] == '+' || s[i] == '-') { 
            i++; 
            continue; 
        } 
        if (s[i] == '(') { 
  
            // global sign for the bracket is 
            // pushed to the stack 
            if (adjSign(s, i))  
                stk.push(stk.top()); 
            else 
                stk.push(!stk.top()); 
        } 
  
        // global sign is popped out which 
        // was pushed in for the last bracket 
        else if (s[i] == ')')  
            stk.pop(); 
          
        else { 
  
            // global sign is positive (we use different  
            // values in two calls of functions so that 
            // we finally check if all vector elements 
            // are 0. 
            if (stk.top())                  
                v[s[i] - 'a'] += (adjSign(s, i) ? add ? 1 : -1 :  
                                                  add ? -1 : 1); 
  
            // global sign is negative here 
            else                 
                v[s[i] - 'a'] += (adjSign(s, i) ? add ? -1 : 1 :  
                                                  add ? 1 : -1); 
        } 
        i++; 
    } 
}

int Solution::solve(string expr1, string expr2) 
{
    
    // Create a vector for all operands and 
    // initialize the vector as 0. 
    vector<int> v(MAX_CHAR, 0); 
  
    // Put signs of all operands in expr1 
    eval(expr1, v, true); 
  
    // Subtract signs of operands in expr2 
    eval(expr2, v, false); 
  
    // If expressions are same, vector must  
    // be 0. 
    for (int i = 0; i < MAX_CHAR; i++)  
        if (v[i] != 0)  
            return false; 
  
    return true;
    
}
