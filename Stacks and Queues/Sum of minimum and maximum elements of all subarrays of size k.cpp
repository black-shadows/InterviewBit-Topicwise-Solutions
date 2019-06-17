from collections import deque 

class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return an integer
    def solve(self, arr, k):
        
        Sum = 0 # Initialize result 
        
        n = len(arr)
      
        # The queue will store indexes of useful elements 
        # in every window 
        # In deque 'G' we maintain decreasing order of 
        # values from front to rear 
        # In deque 'S' we maintain increasing order of 
        # values from front to rear 
        S = deque() 
        G = deque() 
      
      
        # Process first window of size K 
      
        for i in range(k): 
              
            # Remove all previous greater elements 
            # that are useless. 
            while ( len(S) > 0 and arr[S[-1]] >= arr[i]): 
                S.pop() # Remove from rear 
      
            # Remove all previous smaller that are elements 
            # are useless. 
            while ( len(G) > 0 and arr[G[-1]] <= arr[i]): 
                G.pop() # Remove from rear 
      
            # Add current element at rear of both deque 
            G.append(i) 
            S.append(i) 
      
        # Process rest of the Array elements 
        for i in range(k, n): 
              
            # Element at the front of the deque 'G' & 'S' 
            # is the largest and smallest 
            # element of previous window respectively 
            Sum = (Sum%1000000007 + arr[S[0]] + arr[G[0]])%1000000007
      
            # Remove all elements which are out of this 
            # window 
            while ( len(S) > 0 and S[0] <= i - k): 
                S.popleft() 
            while ( len(G) > 0 and G[0] <= i - k): 
                G.popleft() 
      
            # remove all previous greater element that are 
            # useless 
            while ( len(S) > 0 and arr[S[-1]] >= arr[i]): 
                S.pop() # Remove from rear 
      
            # remove all previous smaller that are elements 
            # are useless 
            while ( len(G) > 0 and arr[G[-1]] <= arr[i]): 
                G.pop() # Remove from rear 
      
            # Add current element at rear of both deque 
            G.append(i) 
            S.append(i) 
      
        # Sum of minimum and maximum element of last window 
        Sum = (Sum%1000000007 + arr[S[0]] + arr[G[0]])%1000000007 
      
        return Sum%1000000007
