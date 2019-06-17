void updateindex(vector<int> &index, int a, int ai, int b, int bi) {
    index[a] = ai;
    index[b] = bi;
}

int minSwapsUtil(vector<int> &A, vector<int> &pairs, vector<int> &index, int i, int n) {
    if (i > n)
        return 0;
    if (pairs[A[i]] == A[i+1])
         return minSwapsUtil(A, pairs, index, i+2, n);

    int one = A[i+1];
    int indextwo = i+1;

    int indexone = index[pairs[A[i]]];
    int two = A[index[pairs[A[i]]]];
    swap(A[i+1], A[indexone]);
    updateindex(index, one, indexone, two, indextwo);

    int a = minSwapsUtil(A, pairs, index, i+2, n);

    swap(A[i+1], A[indexone]);
    updateindex(index, one, indextwo, two, indexone);
    one = A[i], indexone = index[pairs[A[i+1]]];

    two = A[index[pairs[A[i+1]]]], indextwo = i;
    swap(A[i], A[indexone]);
    updateindex(index, one, indexone, two, indextwo);
    int b = minSwapsUtil(A, pairs, index, i+2, n);

    swap(A[i], A[indexone]);
    updateindex(index, one, indextwo, two, indexone);
    return 1 + min(a, b);
}

void convertToOneBased(vector<int> &a){
    reverse(a.begin(),a.end());
    a.push_back(0);
    reverse(a.begin(),a.end());
}


vector<int> convertToPairsBasedOnIndexing(vector<vector<int> > &b){
    int n=b.size();
    vector<int> pairs(n+n+1);
    for(int i=0; i<b.size(); ++i){
        pairs[b[i][0]]=b[i][1];
        pairs[b[i][1]]=b[i][0];
    }
    return pairs;
}

int Solution::solve(int A, vector<int> &B, vector<vector<int> > &C) {
    convertToOneBased(B);
    vector<int> pairs=convertToPairsBasedOnIndexing(C);
    vector<int> index(A+A+1);
    for(int i=1; i<=A; ++i)
        index[B[i]]=i;
    return minSwapsUtil(B,pairs,index,1,2*A);
}