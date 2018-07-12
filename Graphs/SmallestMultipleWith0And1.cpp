string Solution::multiple(int A) {
      if(!A) return "0";
    string zeroend="";
    string ans="";
    while(A%10==0) {
        A/=10;
        zeroend.push_back('0');
    }
     while(A%5==0) {
        A/=5;
        zeroend.push_back('0');
    }
     while(A%2==0) {
        A/=2;
        zeroend.push_back('0');
    }
    vector<bool> visited(A,false);
    vector<char> val(A);
    vector<int> p(A);
    queue<int> q;
    int temp=1%A,x;
    visited[temp] = true;
    val[temp]='1';
    q.push(temp);
    
    while(1)
    {
        temp=q.front();
        q.pop();
        if(temp==0)
        {
            temp=0;
            ans.push_back(val[temp]);
            temp=p[temp];
            while(temp!=0)
            {
                ans.push_back(val[temp]);
                temp=p[temp];
            }
            reverse(ans.begin(),ans.end());
            return ans+zeroend;
        }
        x=(temp*10)%A;
        if(!visited[x])
        {
            visited[x]=true;
            val[x]='0';
            p[x]=temp;
            q.push(x);
        }
        x++;
        if(x>=A)    x-=A;
        if(!visited[x])
        {
            visited[x]=true;
            val[x]='1';
            p[x]=temp;
            q.push(x);
        }
    }
}