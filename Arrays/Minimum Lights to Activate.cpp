nt lcount=0;
int findLamp(int index,vector<int> &A,int B){
    int start = index+B-1<A.size()-1?index+B-1:A.size()-1;
    for(int i=start;i>=index;i--){
        if(A[i]==1) 
            return i;
    }
    int end = index-B+1>0?index-B+1:0;
    for(int i=index-1;i>=end;i--){
        if(A[i]==1)
            return i;
    }
    return -1;
}
void lightUpCorr(int index,vector<bool> &corr,int B){
    int i;
    int end = index+B-1<corr.size()-1?index+B-1:corr.size()-1;
    for(i=index;i<=end;i++)
        corr[i] = true;
    for(i = index-1;i>=index-B+1&& i>=0;i--)
        corr[i] = true;
        lcount++;
}
int Solution::solve(vector<int> &A, int B) {
    vector<bool> corr;
    lcount=0;
    corr.resize(A.size(),false);
    for(int i=0;i<A.size();i++){
        if(!corr[i]){
            int lampPos = findLamp(i,A,B);
            //cout<<i<<" "<<lampPos<<endl;
            if(lampPos==-1)
                return -1;
            lightUpCorr(lampPos,corr,B);
        }
    }
    return lcount;
}