#include<bits/stdc++.h>
using namespace std;

struct test{
	int c, a, b;
};

test zbior[1001];

bool compare(const test &x, const test &y)
{
	return x.a<y.a;
}

int n;

int main()
{
	cin>>n;
	
	for(int i=1; i<=n; i++)
	cin>>zbior[i].c>>zbior[i].a>>zbior[i].b;
	
	sort(zbior+1, zbior+1+n, compare);
	
	cout<<"\n";
	for(int i=1; i<=n; i++)
	cout<<zbior[i].c<<" "<<zbior[i].a<<" "<<zbior[i].b<<"\n";
	
}
