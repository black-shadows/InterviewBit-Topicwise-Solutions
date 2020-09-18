int Solution::solve(vector<int> &A, int B) {
    if(A.empty())
    return 0;
sort(A.begin(), A.end());

int i=0;
int j=0;
while(i < A.size() && j < A.size()){
    int k = A[j] - A[i];
    if(k == B && i != j)
        return 1;
    else if(k < B)
        j++;
    else
        i++;
}
return 0;
}
