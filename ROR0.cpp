#include<bits/stdc++.h>
using namespace std;

pair<long long,long long> ext_Euclidean(long long a, long long b)
{
	if(b==0)
	return {1,0};
	
	pair<long long,long long> p=ext_Euclidean(b, a%b);
	return {p.second, p.first-a/b*p.second};
}

int GCD(int a, int b)
{
	pair<int,int> p = ext_Euclidean(a,b);
	return a*p.first+b*p.second;
}

long long LCM(long long a, long long b)
{
	pair<long long,long long> p = ext_Euclidean(a,b);
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

long long a, b;
pair<int,int> p;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);	
	
	cin>>a>>b;
	
	cout<<LCM(a,b);
}
