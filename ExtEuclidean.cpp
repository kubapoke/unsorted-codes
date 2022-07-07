#include<bits/stdc++.h>
using namespace std;

pair<int,int> ext_Euclidean(int a, int b)
{
	if(b==0)
	return {1,0};
	
	pair<int,int> p=ext_Euclidean(b, a%b);
	return {p.second, p.first-a/b*p.second};
}

int a, b;
pair<int,int> p;

int main()
{
	cin>>a>>b;
	
	p=ext_Euclidean(a,b);
	
	cout<<a*p.first+b*p.second;
}
