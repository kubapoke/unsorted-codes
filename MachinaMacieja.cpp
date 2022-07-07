#include<bits/stdc++.h>
using namespace std;

int n, m, k, l;

deque<pair<int,int>> qmin;
vector<int> tab[1000000];

void add(int v, int idx)
{
	while(!qmin.empty() && qmin.back().first>=v) qmin.pop_back();
	qmin.push_back({v,idx});	
}

void remove(int idx)
{
	if(qmin.front().second==idx) qmin.pop_front();
}

int getmin()
{
	if(!qmin.empty()) return (qmin.front().first);
	return 1e9;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m>>k>>l;
	
	for(int i=0; i<n; i++)
	for(int j=0; j<m; j++)
	{
		int a;
		cin>>a;
		
		tab[i].push_back(a);
	}
	
	for(int i=0; i<n; i++)
	{
		qmin.clear();
		
		for(int j=0; j<m; j++)
		{
			add(tab[i][j],j);
			remove(j-l);
			tab[i][j]=getmin();
		}
	}
	
	for(int j=0; j<m; j++)
	{
		qmin.clear();
		
		for(int i=0; i<n; i++)
		{
			add(tab[i][j],i);
			remove(i-k);
			tab[i][j]=getmin();
		}
	}
	
	for(int i=k-1; i<n; i++)
	{
		for(int j=l-1; j<m; j++)
		{
			cout<<tab[i][j]<<" ";
		}
		cout<<"\n";
	}
	
}
