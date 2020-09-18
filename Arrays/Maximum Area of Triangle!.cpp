int retCol(char ch) {
    if(ch=='r') {
        return 0;
    } else if (ch=='g') {
        return 1;
    }
    return 2;
}
int Solution::solve(vector<string> &A) {
    vector<int> minCol(3, INT_MAX);
    vector<int> maxCol(3, INT_MIN);
    vector<vector<int>> colMin(3, vector<int>(A[0].length(),INT_MAX));
    vector<vector<int>> colMax(3, vector<int>(A[0].length(),INT_MIN));
    int cols=A[0].length();
    for(int i=0;i<A.size();i++) {
        for(int j=0;j<A[0].length();j++) {
            int val=retCol(A[i][j]);
            //cout<<val<<endl;
            minCol[val]=min(minCol[val],j);
            maxCol[val]=max(minCol[val],j);
            colMin[val][j]=min(colMin[val][j],i);
            colMax[val][j]=max(colMax[val][j],i);
        }
    }
    double ret=0;
    for(int col=0;col<cols;col++) {
        for(int color1=0;color1<3;color1++) {
            for(int color2=0;color2<3;color2++) {
                if(color1==color2) continue;
                int color3=3-color1-color2;
                if(colMin[color2][col]==INT_MAX || colMin[color1][col]==INT_MAX || minCol[color3]==INT_MAX) 
                    continue;
                ret=max(ret,0.5*(colMax[color1][col]-colMin[color2][col]+1)*(col-minCol[color3]+1));
                ret=max(ret,0.5*(colMax[color1][col]-colMin[color2][col]+1)*(maxCol[color3]-col+1));
            } 
        }
    }
    return ceil(ret);
}