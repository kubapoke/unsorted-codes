#include<bits/stdc++.h>
using namespace std;

struct pkt{
	double x, y;
	double odl;
}punkt[1001];

bool compare(const pkt &a, const pkt &b)
{
	return a.odl<b.odl;
}

int n;

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>n;
	
	for(int i=1; i<=n; i++)
	{
		cin>>punkt[i].x>>punkt[i].y;
		punkt[i].odl=sqrt(pow(punkt[i].x,2)+pow(punkt[i].y,2));
	}
	
	sort(punkt+1, punkt+n+1, compare);
	
	cout<<punkt[1].x<<" "<<punkt[1].y<<" "<<punkt[100].x<<" "<<punkt[100].y<<" "<<punkt[n].x<<" "<<punkt[n].y<<" ";
	
	return 0;
}
