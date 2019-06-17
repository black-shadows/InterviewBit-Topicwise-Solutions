vector<int> printMedians(vector<int> arr, int n) 
{ 
    // max heap to store the smaller half elements 
    priority_queue<double> s; 
    
    vector<int> ans;
  
    // min heap to store the greater half elements 
    priority_queue<double,vector<double>,greater<double> > g; 
  
    double med = arr[0]; 
    s.push(arr[0]); 
  
    ans.push_back(med);
  
    //return ans;
  
    // reading elements of stream one by one 
    /*  At any time we try to make heaps balanced and 
        their sizes differ by at-most 1. If heaps are 
        balanced,then we declare median as average of 
        min_heap_right.top() and max_heap_left.top() 
        If heaps are unbalanced,then median is defined 
        as the top element of heap of larger size  */
    for (int i=1; i < n; i++) 
    { 
        double x = arr[i]; 
  
        // case1(left side heap has more elements) 
        if (s.size() > g.size()) 
        { 
            if (x < med) 
            { 
                g.push(s.top()); 
                s.pop(); 
                s.push(x); 
            } 
            else
                g.push(x); 
  
            //med = (s.top() + g.top())/2.0; 
            
            med = s.top();
        } 
  
        // case2(both heaps are balanced) 
        else if (s.size()==g.size()) 
        { 
            if (x < med) 
            { 
                s.push(x); 
                med = (double)s.top(); 
            } 
            else
            { 
                g.push(x); 
                med = (double)g.top(); 
            } 
        } 
  
        // case3(right side heap has more elements) 
        else
        { 
            if (x > med) 
            { 
                s.push(g.top()); 
                g.pop(); 
                g.push(x); 
            } 
            else
                s.push(x); 
  
            //med = (s.top() + g.top())/2.0; 
            
            med = s.top();
        } 
  
        ans.push_back(med);
    }
    
    return ans;
} 


vector<int> Solution::solve(vector<int> &A) 
{
    
    return printMedians(A, A.size());
    
}
