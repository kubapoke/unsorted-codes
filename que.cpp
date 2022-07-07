#include<bits/stdc++.h>
using namespace std;

priority_queue<int> PQ;
int n, q, l, r, x, tab[1000001], w;

int main()
{
	cin>>n>>q;
	for(int i=1; i<=n; i++)
	cin>>tab[i];
	
	for(int i=1; i<=q; i++)
	{
		w=0;
		while(!PQ.empty())
		PQ.pop();
		
		cin>>l>>r>>x;
		
		for(int j=l; j<=r; j++)
		{
			PQ.push(tab[j]);
		}
		
		for(int j=1; j<=x; j++)
		{
			w+=PQ.top();
			PQ.pop();
		}
		
		cout<<w<<"\n";
	}
	
}
