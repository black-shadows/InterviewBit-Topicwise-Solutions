int Solution::solve(vector<int> &arr) 
{
    
    int n = arr.size();
    
    priority_queue<int, vector<int>, greater<int> > pq(arr.begin(), arr.end()); 
  
    // Initialize result 
    int res = 0; 
  
    // While size of priority queue is more than 1 
    while (pq.size() > 1) { 
        // Extract shortest two ropes from pq 
        int first = pq.top(); 
        pq.pop(); 
        int second = pq.top(); 
        pq.pop(); 
  
        // Connect the ropes: update result and 
        // insert the new rope to pq 
        res += first + second; 
        pq.push(first + second); 
    } 
  
    return res;
    
}
