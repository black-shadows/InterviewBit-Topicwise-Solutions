int func(int n,int m,vector<vector<int> > &C,vector<vector<int> > &D){
    int flag[109][109]={};
        vector<int> x;
        vector<int> y;
        vector<int> c;
        for(int i=0; i<n; i++){
            int temp1=C[i][0];
            int temp2=C[i][1];
            assert(temp1>=0 && temp1<=100);
            assert(temp2>=0 && temp2<=100);
            if(flag[temp1][temp2]==1)
                assert(-1>0);
            flag[temp1][temp2]=1;
            x.push_back(temp1);
            y.push_back(temp2);
            c.push_back(1);
        }
        for(int i=0; i<m; i++){
            int temp1=D[i][0];
            int temp2=D[i][1];
            assert(temp1>=0 && temp1<=100);
            assert(temp2>=0 && temp2<=100);
            if(flag[temp1][temp2]==1)
                assert(-1>0);
            flag[temp1][temp2]=1;
            x.push_back(temp1);
            y.push_back(temp2);
            c.push_back(0);
        }
        assert((int)c.size()==(n+m));
        int n1=(int)x.size();
        int d[n1][n1];
        for (int i=0; i<n1; i++)
            for (int j=0; j<n1; j++)
                d[i][j]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
        for (int i=0; i<n1; i++)  if (c[i]==0)
            for (int j=0; j<n1; j++)
                for (int k=0; k<n1; k++)
                    d[j][k]=min(d[j][k], max(d[j][i], d[i][k]));
        int sol=0;
        for (int i=0; i<n1; i++)
            for (int j=0; j<n1; j++)
                if (c[i]==0 && c[j]==1)
                    sol=max(sol, d[i][j]);
        assert(sol>=0&&sol<=INT_MAX);
        return sol;
}
int Solution::solve(int A, int B, vector<vector<int> > &C, vector<vector<int> > &D) {
    return func(A,B,C,D);
}
