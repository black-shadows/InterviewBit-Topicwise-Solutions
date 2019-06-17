class Solution:
    # @param A : list of list of integers
    # @param B : integer
    # @return a list of list of integers
    def solve(self, points, K):
        
        points.sort(key = lambda K: K[0]**2 + K[1]**2) 
  
        return points[:K] 
