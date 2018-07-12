vector<vector<int> > Solution::queenAttack(vector<string> &A) {
    if (A.size()==0 || A[0].size()==0) return vector<vector<int> >(0);
    int n = A.size();
    int m = A[0].size();
    vector<vector<int> > result(n, vector<int>(m, 0));
    
    int *row = new int[n];
    int *column = new int[m];
    int *cross1 = new int[n+m];
    int *cross2 = new int[n+m];
    memset(row, 0, sizeof(int)*n);
    memset(column, 0, sizeof(int)*m);
    memset(cross1, 0, sizeof(int)*(n+m));
    memset(cross2, 0, sizeof(int)*(n+m));
    
    for (int i=0; i<n; i++)
    for (int j=0; j<m; j++){
        if (row[i]>0) result[i][j]++;
        if (column[j]>0) result[i][j]++;
        if (cross1[i+j]>0) result[i][j]++;
        if (cross2[i-j+m]>0) result[i][j]++;
        
        if (A[i][j]=='1'){
            row[i]++;
            column[j]++;
            cross1[i+j]++;
            cross2[i-j+m]++;
        }
    }
    
    memset(row, 0, sizeof(int)*n);
    memset(column, 0, sizeof(int)*m);
    memset(cross1, 0, sizeof(int)*(n+m));
    memset(cross2, 0, sizeof(int)*(n+m));
    
    for (int i=n-1; i>=0; i--)
    for (int j=m-1; j>=0; j--){
        if (row[i]>0) result[i][j]++;
        if (column[j]>0) result[i][j]++;
        if (cross1[i+j]>0) result[i][j]++;
        if (cross2[i-j+m]>0) result[i][j]++;
        
        if (A[i][j]=='1'){
            row[i]++;
            column[j]++;
            cross1[i+j]++;
            cross2[i-j+m]++;
        }        
    }
    return result;
}