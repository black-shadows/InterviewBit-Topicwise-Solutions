struct Box{
	int T,F;
	Box():T(0),F(0){}
};
Box util(char c,Box b1, Box b2){
	Box b;
	if(c=='|'){
		b.T=b1.T*b2.F+b1.F*b2.T+b1.T*b2.T;
		b.F=b1.F*b2.F;
	}
	else if(c=='&'){
		b.F=b1.T*b2.F+b1.F*b2.T+b1.F*b2.F;
		b.T=b1.T*b2.T;
	}
	else {
		b.F=b1.F*b2.F+b1.T*b2.T;
		b.T=b1.F*b2.T+b1.T*b2.F;
	}
	b.T%=1003;
	b.F%=1003;
	return b;
}
Box method(Box **arr,int i,int l,string s1, string s2){
	int m=0,n=s1.length();
	Box b1;
	for(m=i;m<l;m++){
		Box b2;
		b2=util(s2[m],arr[i][n-m-1],arr[m+1][n-l-1]);
		b1.T+=b2.T;
		b1.F+=b2.F;
		b1.T%=1003;
		b1.F%=1003;

	}
	return b1;
}
int Solution::cnttrue(string A) {
    string s=A;
    string s1="",s2="";
	int i,j,k,l;
	for(i=0;i<s.length();i++){
		if(s[i]=='T' | s[i]=='F')
			s1+=s[i];
		else s2+=s[i];
	}
	int n=s1.length();
	Box **arr=new Box *[n];
	for(i=0;i<n;i++)
		arr[i]=new Box[n-i];
	
	for(i=0;i<n;i++){
		Box b1;
		if(s1[i]=='T')
			b1.T=1;
		else b1.F=1;
		arr[i][n-i-1]=b1;
	}
	for(k=1;k<n;k++){
		i=0;j=n-k-1;l=k;
		while(i<n-k){
			arr[i][j]=method(arr,i,l,s1,s2);
			i++;j--;l++;
		}
	}
	return arr[0][0].T;
}