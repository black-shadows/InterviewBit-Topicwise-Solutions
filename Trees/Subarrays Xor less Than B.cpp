#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define line cout<<"----------------------------------"<<endl
#define fast ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define filein freopen("input.txt","r",stdin)
#define fileout freopen("output.txt","w",stdout)
using namespace std;
ll k;
struct node
{
    ll mark;
    node *next[4];
    node()
    {
        mark=false;
        for(ll i=0;i<3;i++) next[i]=NULL;
    }
};
node *root;
void add(string str)
{
    node *temp=root;
    ll cnt=0;
    for(ll i=0;i<str.size();i++)
    {
        ll d=str[i]-'0';
        if(temp->next[d]==NULL)
        {
            temp->next[d]=new node();
        }
        temp=temp->next[d];
        temp->mark++;
    }
}
ll check (string str,string str1)
{
    ll ans=0;
    node *temp=root;
    for(ll i=0;i<str.size();i++)
    {
        if(str[i]=='0' and str1[i]=='1')
        {
            if(temp->next[0]!=NULL) ans+=temp->next[0]->mark;
            if(temp->next[1]==NULL) return ans;
            temp=temp->next[1];
        }
        else if(str[i]=='0' and str1[i]=='0')
        {
            if(temp->next[0]!=NULL) temp=temp->next[0];
            else return ans;
        }
        else if(str[i]=='1' and str1[i]=='1')
        {
            if(temp->next[1]!=NULL) ans+=temp->next[1]->mark;
            if(temp->next[0]==NULL) return ans;
            temp=temp->next[0];
        }
        else if(str[i]=='1' and str1[i]=='0')
        {
            if(temp->next[1]==NULL) return ans;
            temp=temp->next[1];
        }
    }
    return ans;
}
void del(node* temp)
{
    for(ll i=0;i<3;i++)
    {
        if(temp->next[i]) del(temp->next[i]);
    }
    delete(temp);
}
ll ara[100009];
string str1;

int Solution::solve(vector<int> &A, int B) 
{
    
    ll t;
    str1="";
    k = B;
    ll n = A.size();
    ll m=k;
    while(m)
    {
        if(m%2==0) str1+='0';
        else str1+='1';
        m/=2;
    }
    ll maxi=-1;
    for(ll i=0;i<n;i++)
    {
        
        ara[i] = A[i];
        maxi=max(maxi,ara[i]);
        
    }
      ll log=log2(maxi)+1;
      root=new node();
      string str;
      for(ll i=0;i<log;i++) str+='0';
      for(ll i=str1.size();i<log;i++) str1+='0';
        reverse(str1.begin(),str1.end());
      add(str);
      ll sum=0;
      ll ans=0;
      for(ll i=0;i<n;i++)
      {
          str="";
          sum=sum^ara[i];
          ll d=sum;
          while(d)
          {
              if(d%2==0) str+='0';
              else str+='1';
              d>>=1;
          }
          for(ll i=str.size();i<log;i++) str+='0';
            reverse(str.begin(),str.end());
            ans+=check(str,str1);
          add(str);
      }
      if((int)log2(k)+1>log)
      {
          ans=n*(n+1)/2;
      }
      return ans%mod;
      del(root);
}
