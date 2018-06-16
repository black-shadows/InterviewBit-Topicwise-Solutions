struct cell{
    int x,y,dis;
    cell() {} //declaring constructor function
    cell(int x, int y, int dis): x(x), y(y), dis(dis) {} // initializing constructor
};

bool isInside(int x, int y, int N, int M){
    if((x>=1 && x<=N) && (y>=1 && y<=M)) return true;
    return false;
}

int Solution::knight(int N, int M, int x1, int y1, int x2, int y2) {
    // Do not write main() function.
    //Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int dx[]={-2,-1,1,2,-2,-1,1,2};
    int dy[]={-1,-2,-2,-1,1,2,2,1};
    queue<cell> q;
    q.push(cell(x1, y1,0));
    int x, y;
    bool visit[N+1][M+1];
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            visit[i][j]=false;
        }
    }
    visit[1][1]= true;
    
    
    while(!q.empty()){
        cell t= q.front();
        q.pop();
        if(t.x==x2 && t.y==y2) return t.dis;
        for(int i=0;i<8;i++){
            x= t.x+ dx[i];
            y= t.y+ dy[i];
            if(isInside(x,y,N,M) && !visit[x][y]){
                q.push(cell(x,y,t.dis+1));
                visit[x][y]=true;
            }
        }
    }
    return -1;
}