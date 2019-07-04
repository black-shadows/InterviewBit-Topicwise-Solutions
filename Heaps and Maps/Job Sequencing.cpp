struct Job {
   int dead;
   int profit;
};

bool compare(const Job &a, const Job &b) {
     return (a.profit > b.profit);
}

int solveit(vector<int> &A,vector<int> &B){
    int n=A.size();
    Job a[n];
    for(int i=0; i<n; ++i){
        a[i].dead=A[i];
        a[i].profit=B[i];
    }
    sort(a,a+n,compare);
    int result[n];
    bool slot[n];
    for (int i=0; i<n; i++)
        slot[i] = false;
    for(int i=0; i<n; i++) {
       for (int j=min(n, a[i].dead)-1; j>=0; j--) {
            if(slot[j]==false) {
                result[j] = i;
                slot[j] = true;
                break;
          }
       }
    }
    int ans=0;
    for(int i=0; i<n; i++)
       if(slot[i])
            ans+=a[result[i]].profit;

    return ans;
}

int Solution::solve(vector<int> &A, vector<int> &B) {
    return solveit(A,B);
}