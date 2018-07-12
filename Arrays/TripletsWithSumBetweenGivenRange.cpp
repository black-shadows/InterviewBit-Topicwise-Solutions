double min_element(vector<double> A)  //return minimum element
{ double min=A[0];
	for(int i=0;i<A.size();i++)
{
	if(A[i]<min)
	{
		min=A[i];
	}
	
	}
	return min;
}
int Solution::solve(vector<string> &a) {
vector<double> A,B,C;

for(int i=0;i<a.size();i++)
{ char b[20];
for(int j=0;j<a[i].length();j++)
  {
  	b[j]=a[i][j];
  }
if(0.0<atof(b)&&atof(b)<((double)2.0/(double)3.0)) // atof converts string to double
{
	A.push_back(atof(b));
	
}
else if((double)2.0/(double)3.0<=atof(b)&&atof(b)<=1.0)
{
	B.push_back(atof(b));
	
}
else if(1.0<atof(b)&&atof(b)<2.0)
{
	C.push_back(atof(b));
	
}
	
}


//1
int res=0;

if(A.size()>=3)
{
priority_queue<double> q(A.begin(),A.end());  //priority queue used to get max 3 elements in O(logn) time
double m=0;
for(int i=0;i<=2;i++)
{
	m+=q.top();
	q.pop();
}

if(m>1.0)
{
	res=1;
	return res;
}

}
//2
if(A.size()>=2&&B.size()>=1)
{
priority_queue<double> q1(A.begin(),A.end());  //priority queue used to get max 2 elements in O(logn) time

double m1=0;
for(int i=0;i<=1;i++)
{
	m1+=q1.top();
	q1.pop();
}

for(int i=0;i<B.size();i++)
{
	if(1-m1<B[i]&&B[i]<2-m1)
	{
		res=1;
		return res;
	}

}

}

//3
if(A.size()>=2&&C.size()>=1)
{
priority_queue<double,std::vector<double>, std::greater<double> > q2(A.begin(),A.end());  //priority queue used to get min 2 elements in O(logn) time
double m2=0;
for(int i=0;i<=1;i++)
{
   m2+=q2.top();
   q2.pop();	
}

double min=min_element(C);
	

if(m2+min<2.0)
{
	res=1;
	return res;
}

}

//4
if(B.size()>=2&&A.size()>=1)
{
priority_queue<double,std::vector<double>, std::greater<double> > q3(B.begin(),B.end()); //priority queue used to get min 2 elements in O(logn) time

double m3=0;
for(int i=0;i<=1;i++)
{
	m3+=q3.top();
	q3.pop();
}

for(int i=0;i<A.size();i++)
{
	if(A[i]<2-m3)
	{
		res=1;
		return res;
	}
	
}

}

//5
if(A.size()>=1&&B.size()>=1&&C.size()>=1)
{
int res3=0;
double min1=min_element(A);
double min2=min_element(B);
double min3=min_element(C);
if(min1+min2+min3<2&&min1+min2+min3>1)
{
	res=1;
	return res;
}

}

return res;
// Time complexity =O(logn)+O(n)
//hence,Time complexity=O(n)

}