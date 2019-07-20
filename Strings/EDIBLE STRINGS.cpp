const int N=100005;

int p[N];
int tc=0;
void pre(){
    if(tc)
        return;
    p[1]=1;
    tc=1;
    for(int i=4; i<N; i+=2)
        p[i]=1;
    for(int i=3; i*i<N; i+=2)
        if(!p[i])
            for(int j=i*i; j<N; j+=i+i)
                p[j]=0;
}

bool vowel(char a){
    return (a=='a'||a=='e'||a=='i'||a=='o'||a=='u');
}

string Solution::solve(string A){
    pre();
    for(auto &it:A)
        assert(it>='a'&&it<='z');
    assert(A.size()>=1&&A.size()<=100000);
    int y=1;
    for(int i=1; i<A.size()+1; ++i){
        if(vowel(A[i-1])&&p[i]==1){
            y=0;
            break;
        }
    }
    if(y)
        return "YES";
    else
        return "NO";
    
}