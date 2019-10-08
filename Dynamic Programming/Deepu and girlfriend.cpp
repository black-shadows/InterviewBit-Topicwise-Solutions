string Solution::solve(int A, vector<int> &B) {
    bool game[A+1];
    memset(game,0,sizeof(game));
    for(int i=0;i<A;i++){
        if(game[i]==false){
            for(auto u:B){
                if(i+u==A){
                    game[i+u]=true;
                }
                else if(i+u<A){
                    game[i+u]=true;
                }
            }
        }
    }

    
    if(game[A]==true){
        return "Little Deepu";
    }
    return "Kate";
    
}
