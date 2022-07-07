//Program P-10
#include<bits/stdc++.h>
using namespace std;

int n, wartl[36], wartr[36], wartu[36], wartd[36];
map<pair<int,int>,int> con;
set<string> wyn;
set<string>::iterator it;

void addcon(string &s)
{
	int a=s[0], b=s[1];
	
	if(a<='9')
	a-='0';
	else
	{
		a-='A';
		a+=10;
	}
	
	if(b<='9')
	b-='0';
	else
	{
		b-='A';
		b+=10;
	}
	
	con[{min(a,b),max(a,b)}]=1;
}

string revcon(int a, int b)
{
	string s;
	char c, d;
	
	if(a<10)
	c=a+'0';
	else
	c=a-10+'A';
	
	s.push_back(c);
	
	if(b<10)
	d=b+'0';
	else
	d=b-10+'A';
	
	s.push_back(d);
	
	return s;
}

int main()
{
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		string st;
		cin>>st;
		addcon(st);
	}
	
	for(int i=0; i<36; i++)
	{
		if(i%6!=0)
		if(con[{i-1,i}]==1)
		wartl[i]=wartl[i-1]+1;
	}
	
	for(int i=0; i<36; i++)
	{
		if(i>5)
		if(con[{i-6,i}]==1)
		wartu[i]=wartu[i-6]+1;
	}
	
	for(int i=35; i>=0; i--)
	{
		if(i%6!=5)
		if(con[{i,i+1}]==1)
		wartr[i]=wartr[i+1]+1;
	}
	
	for(int i=35; i>=0; i--)
	{
		if(i<30)
		if(con[{i,i+6}]==1)
		wartd[i]=wartd[i+6]+1;
	}
	
	
	for(int i=0; i<36; i++)
	{
		for(int j=i+7; j<=i+min(wartr[i],wartd[i])*7; j+=7)
		{
			if(wartl[j]>=(j-i)/7 && wartu[j]>=(j-i)/7)
			wyn.insert(revcon(i,j));
		}
	}
	
	cout<<wyn.size()<<"\n";
	
	for(it=wyn.begin(); it!=wyn.end(); it++)
	cout<<*it<<"\n";
}
