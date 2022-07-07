#include<bits/stdc++.h>
using namespace std;

set<int> pla[2001];
set<int>::iterator it1, it2;
int n, w, a, b, tab[2001][2001];

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>a>>b;
		pla[a+1000].insert(b+1000);
		tab[a+1000][b+1000]=1;
	}

	for(int i=0; i<=2000; i++)
	{
		for(it1=pla[i].begin(); it1!=pla[i].end(); ++it1)
		{
			for(it2=it1, ++it2; it2!=pla[i].end(); ++it2)
			{	
				int roz=*it2-*it1;
				
				if(i+roz>2000)
				break;
				
				if(tab[i+roz][*it1]==1&&tab[i+roz][*it2]==1)
				w++;
					
			}
		}
	}
	
	cout<<w;
}
