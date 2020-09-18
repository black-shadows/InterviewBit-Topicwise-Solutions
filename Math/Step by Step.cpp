int Solution::solve(int A) {
int target = abs(A);
int n = ceil((-1.0 + sqrt(1 + 8.0 * target)) / 2);
int sum = n * (n + 1) / 2;
if (sum == target)
return n;

int d = sum - target;
if ((d & 1) == 0)
    return n;
else
    return n + ((n & 1) ? 2 : 1);
}