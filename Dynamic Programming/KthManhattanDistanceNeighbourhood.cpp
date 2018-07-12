#include<bits/stdc++.h>
typedef pair<int,pair<int,int>> kamesh;
bool fun(kamesh a, kamesh b){
    return a.first>b.first;
}
vector<vector<int> > Solution::solve(int A, vector<vector<int> > &B) {
    int n=B.size();
    int m1=B[0].size();
    vector<kamesh> m(n*m1);
    int k=0;
    for(int i=0;i<B.size();i++){
        for(int j=0;j<B[i].size();j++){
            m[k]=make_pair(B[i][j],make_pair(i,j));
            k++;
        }
    }
    sort(m.begin(),m.end(),fun);
    int x=m.size();
    vector<vector<int>> v(B.size(),vector<int> (B[0].size()));
    for(int i=0;i<B.size();i++){
        for(int j=0;j<B[i].size();j++){
            for(int l=0;l<x;l++){
                if((abs(i-(m[l].second).first)+abs(j-(m[l].second).second))<=A){
                    v[i][j]=B[(m[l].second).first][(m[l].second).second];
                    break;
                }
            }
        }
    }
    
    return v;
}