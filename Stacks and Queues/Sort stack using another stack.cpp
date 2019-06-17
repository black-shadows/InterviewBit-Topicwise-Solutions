vector<int> Solution::solve(vector<int> &A) 
{
    
    stack<int> input;
    
    for(int i=A.size()-1; i>=0; i--)
    {
        
        input.push(A[i]);
        
    }
    
    stack<int> tmpStack; 
  
    while (!input.empty()) 
    { 
        // pop out the first element 
        int tmp = input.top(); 
        input.pop(); 
  
        // while temporary stack is not empty and top 
        // of stack is greater than temp 
        while (!tmpStack.empty() && tmpStack.top() > tmp) 
        { 
            // pop from temporary stack and push 
            // it to the input stack 
            input.push(tmpStack.top()); 
            tmpStack.pop(); 
        } 
  
        // push temp in tempory of stack 
        tmpStack.push(tmp); 
    } 
    
    vector<int> ans;
  
    for(int i=0; i<A.size(); i++)
    {
        
        ans.push_back(tmpStack.top());
        
        tmpStack.pop();
        
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
    
}
