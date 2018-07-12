void mxstr(vector<string> &v){
    int mx2,u,w,e,t,x,y,z,d,f,n=v.size();mx2=0;
    for(int j=0;j<n-1;j++){
        for(int k=j+1;k<n;k++){
            string s1=v[j];string s2=v[k];
            if(s1.find(s2)!=string::npos)
            v.erase(v.begin()+k);
            else if(s2.find(s1)!=string::npos)
            v.erase(v.begin()+j);
            else{
                int mx,mx1,l=0;mx=mx1=0;
                while(s2[l]){
                    if(s2[l]==s1[0]){
                        int r=l,p=0,m=0;
                        while(s2[r]&&s2[r]==s1[p]){
                            r++;
                            p++;
                            m++;
                        }
                        if(!s2[r]&&m){
                            mx=m;
                            t=p;
                            break;
                        }
                    }
                    l++;
                }
                l=0;
                while(s1[l]){
                    if(s1[l]==s2[0]){
                        int r=l,p=0,m=0;
                        while(s1[r]&&s1[r]==s2[p]){
                            r++;
                            p++;
                            m++;
                        }
                        if(!s1[r]&&m){
                            mx1=m;
                            x=p;
                            break;
                        }
                    }
                    l++;
                }
                if(mx>=mx1){
                    f=mx;
                    y=k;
                    z=j;
                    d=t;
                }
                else{
                    f=mx1;
                    y=j;
                    z=k;
                    d=x;
                }
            }
            if(mx2<f){
                mx2=f;
                u=y;
                w=z;
                e=d;
            }
        }
    }
    if(!mx2){
        u=0;
        w=1;
        e=0;
    }
    string q=v[w].substr(e);
    v[u]+=q;
    v.erase(v.begin()+w);
}
int Solution::solve(vector<string> &A) {
    int n=A.size();
    while(A.size()!=1)
    mxstr(A);
    return A[0].length();
}