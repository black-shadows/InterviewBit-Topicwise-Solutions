class Solution:
    # @param A : integer
    # @return an integer
    def solve(self, k):
        
        mid = 0
        i = k;
        i >>= 1
        while i:       #这组循环统计整数二进制形式下最开头的1是多少位
            mid += 1
            i >>= 1
     
        ans = 0
        mid = 1<<mid;  #得到最初k的对称中心位置
        while k != 1 and mid != k:
            if mid > k:         #不是小于k的中心点就找更小的中心点
                mid >>= 1
                continue
            k -= mid
            k = mid - k         #得到对称位置
            ans ^= 1
            mid >>= 1
        
        return ans
