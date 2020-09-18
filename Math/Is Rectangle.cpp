int Solution::solve(int A, int B, int C, int D) {
    map<int,int> m;
    m[A]++;
    m[B]++;
    m[C]++;
    m[D]++;
    
    if(m.size()==2)
    {
        for(auto it: m)
        {
            if(it.second!=2){return 0;}
        }
        return 1;
    }
    else
    {
        return 0;
    }
}
