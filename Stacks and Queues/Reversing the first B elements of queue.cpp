vector<int> reverseQueueFirstKElements(int k, queue<int>& Queue) 
{ 
    
    vector<int> ans;
    
    if (Queue.empty() == true || k > Queue.size()) 
        return ans; 
    if (k <= 0) 
        return ans; 
  
    stack<int> Stack; 
  
    /* Push the first K elements into a Stack*/
    for (int i = 0; i < k; i++) { 
        Stack.push(Queue.front()); 
        Queue.pop(); 
    } 
  
    /* Enqueue the contents of stack 
       at the back of the queue*/
    while (!Stack.empty()) { 
        Queue.push(Stack.top()); 
        Stack.pop(); 
    } 
  
    /* Remove the remaining elements and  
       enqueue them at the end of the Queue*/
    for (int i = 0; i < Queue.size() - k; i++) { 
        Queue.push(Queue.front()); 
        Queue.pop(); 
    } 

    while(!Queue.empty())
    {
        
        ans.push_back(Queue.front());
        
        Queue.pop();
        
    }
    
    return ans;
    
} 

vector<int> Solution::solve(vector<int> &A, int B) 
{
    
    queue<int> q;
    
    for(int i=0; i<A.size(); i++)
    {
        
        q.push(A[i]);
        
    }
  
    return reverseQueueFirstKElements(B, q);
    
}
