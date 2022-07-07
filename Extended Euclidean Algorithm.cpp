#include<bits/stdc++.h>
using namespace std;

pair<int,int> ext_Euclidean(int a, int b)
{
	if(b==0)
	return {1,0};
	
	pair<int,int> p=ext_Euclidean(b, a%b);
	return {p.second, p.first-a/b*p.second};
}

int GCD(int a, int b)
{
	pair<int,int> p = ext_Euclidean(a,b);
	return a*p.first+b*p.second;
}

long long LCM(int a, int b)
{
	pair<int,int> p = ext_Euclidean(a,b);
	return abs(a*b)/(a*p.first+b*p.second);
}

long long MMI(int a, int b)
{
	pair<int,int> p = ext_Euclidean(a,b);
	
	if(a*p.first+b*p.second==1)
	{
		if(p.first<0)
		p.first+=b;
		
		return p.first;
	}
	
	return -1; //MMI doesn't exist
}

int a, b;
pair<int,int> p;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);	
	
	cin>>a>>b;
	
	p=ext_Euclidean(a,b);
	
	cout<<"GCD("<<a<<", "<<b<<") = "<<a<<"*"<<p.first<<" + "<<b<<"*"<<p.second<<" = "<<GCD(a,b)<<"\n\n";
	cout<<"LCM("<<a<<", "<<b<<") = "<<a<<"*"<<b<<" / GCD("<<a<<", "<<b<<") = "<<LCM(a,b)<<"\n\n";
	
	if(a*p.first+b*p.second==1)
	{
		cout<<"Modular multiplicative inverse of "<<a<<" from "<<b<<" is "<<MMI(a,b);
	}
}
