int pre[500010];
int val[500010];

void ini(){
    for(int i=0;i<500010;++i)   pre[i]=0;
    for(int i=0;i<500010;++i)   val[i]=0;
}

void update(int idx,int x){
    for(;idx<500010;idx+=(idx&-idx))
        pre[idx]+=x;
}

long long query(int idx){
    long long res=0;
    for(;idx>0;idx-=(idx&-idx)){
        res += pre[idx];
    }
    return res;
}

vector<int> Solution::solve(int A, vector<vector<int> > &B) {
    int q=  B.size();
    ini();
    vector<int> ans;
    for(int i=0;i<q;++i){
        if(B[i][0]==1){
            update(B[i][1],1);
        }else if(B[i][0]==2){
            if(query(B[i][1])-query(B[i][1]-1)!=0){
                update(B[i][1],-1);
            }
        }else{
            ans.push_back(query(B[i][2])-query(B[i][1]-1));
        }
    }
    return ans;
}

