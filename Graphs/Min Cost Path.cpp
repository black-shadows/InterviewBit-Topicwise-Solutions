int Solution::solve(int A, int B, vector<string> &C) {
    // vector<vector<int> > color(A, vector<int>(B,0));
    vector<vector<int> > tot(A,vector<int>(B,100000000));
    deque<pair<int,int>> dq;
    dq.push_back(make_pair(0,0));
    tot[0][0]=0;
    while(!dq.empty()){
        pair<int,int> temp=dq.front();
        dq.pop_front();
        int x=temp.first, y=temp.second;
        // cout<<x<<" "<<y<<endl;
        if(x>0 && tot[x-1][y]>tot[x][y]+(C[x][y]!='U')){
            tot[x-1][y]=tot[x][y]+(C[x][y]!='U');
            if(C[x][y]=='U'){
                dq.push_front(make_pair(x-1,y));
            } else {
                dq.push_back(make_pair(x-1,y));
            }
        }
        if(x<A-1 && tot[x+1][y]>tot[x][y]+(C[x][y]!='D')){
            tot[x+1][y]=tot[x][y]+(C[x][y]!='D');
            if(C[x][y]=='D'){
                dq.push_front(make_pair(x+1,y));
            } else {
                dq.push_back(make_pair(x+1,y));
            }
        }
        if(y>0 && tot[x][y-1]>tot[x][y]+(C[x][y]!='L')){
            tot[x][y-1]=tot[x][y]+(C[x][y]!='L');
            if(C[x][y]=='L'){
                dq.push_front(make_pair(x,y-1));
            } else dq.push_back(make_pair(x,y-1));
        }
        if(y<B-1 && tot[x][y+1]>tot[x][y]+(C[x][y]!='R')){
            // cout<<"lol"<<endl;
            tot[x][y+1]=tot[x][y]+(C[x][y]!='R');
            if(C[x][y]=='R')dq.push_front(make_pair(x,y+1));
            else dq.push_back(make_pair(x,y+1));
        }
    }

    return tot[A-1][B-1];
}
