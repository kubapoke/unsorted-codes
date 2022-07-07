#include<bits/stdc++.h>
using namespace std;

struct bm{
	long long p, r, pocz, kon;
}bomb[200001];

int n, w=1;
long long currkon=-1e18-1;
stack<long long> s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>bomb[i].p>>bomb[i].r;
		bomb[i].pocz=bomb[i].p-bomb[i].r;
		bomb[i].kon=bomb[i].p+bomb[i].r;
	}
	
	for(int i=0; i<n; i++)
	{
		if(i>0)
		if(bomb[i].p>currkon)
		{
			w++;
			s.push(bomb[i-1].p);
		}
		
		while(1)
		{
			if(s.empty()) break;
			if(bomb[i].pocz>s.top()) break;
			
			s.pop();
			w--;
		}
		
		currkon=max(currkon,bomb[i].kon);
	}
	
	cout<<w;
}
