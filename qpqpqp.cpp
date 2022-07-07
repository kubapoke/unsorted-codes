#include<bits/stdc++.h>
using namespace std;

struct pkt{
	int x, y, r;
}punkt[1000001];

bool comp1(const pkt &a, const pkt &b)
{
	return a.r<b.r;
}

int n, w, a, b, tab[2001][2001];

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>a>>b;
		punkt[i].x=a+1000; punkt[i].y=b+1000; punkt[i].r=a-b;
		tab[a+1000][b+1000]=1;
	}
	
	sort(punkt,punkt+n,comp1);
	
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; i<n; j++)
		{
			if(punkt[i].r!=punkt[j].r)
			break;
			
			if(tab[punkt[i].x][punkt[j].y]==1&&tab[punkt[j].x][punkt[i].y]==1)
			w++;
		}
	}

	cout<<w;
}
