vector<int> Solution::solve(int A, int B) {
    long long a1,a2;
    a1 = 0;
    long long sz = A;
    for(int i=0;i<=B;i++){
        long long add =(1ll<<i);
        if(i==B){
            a1 = min(sz,(1ll<<i));   
        }
        sz=max((long long)0,sz-add);
        if(sz==0)break;
    }
    vector<long long>ctr;
    sz = A;
    int idx = 0;
    while(sz){
        // cout<<idx<<" "<<v<<endl;
        if((1<<idx)<sz){
            ctr.push_back((1ll<<idx));
            sz-=(1ll<<idx);
        }else{
            ctr.push_back(sz);
            sz = 0;
        }
        idx++;
    }
    // for(int i=0;i<ctr.size();i++)
    //     cout<<i<<" "<<ctr[i]<<"\n";
    a2 = ctr.back();
    idx = 1;
    int ridx = ctr.size()-2;
    while(idx<=B){
        a2 = ceil(a2/2.0);
        idx++;
        ridx--;
    }
    
    // cout<<ridx<<" "<<a2<<endl;
    if(ridx>=0)
        a2+=(ctr[ridx]-ceil(a2/2.0));
    else if(ridx!=-1)
        a2 = 0;
    vector<int>ret;
    ret.push_back(a1);
    ret.push_back(a2);
    return ret;
}
