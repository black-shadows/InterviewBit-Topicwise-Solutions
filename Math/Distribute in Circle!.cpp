int Solution::solve(int A, int B, int C) {
    
    return (A%B+C%B)%B-1;
}