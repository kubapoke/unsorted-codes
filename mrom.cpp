#include<bits/stdc++.h>
using namespace std;
//7 5 3 3 4 1 9 11 1 2 1 4 4 3 4 5 4 6 6 7

const int N=1e6+1;

int n, g, k, m, a, b, st1, st2, stop[N], pocz[N], kon[N], poczodw[N], konodw[N];
long long w;
vector<int> tree[N];
set<int> mro;
set<int>::iterator it1, it2, st, ed, it3;

void dfs(int v, int p)
{
	if(v!=st1&&v!=st2)
	{
		pocz[v]=poczodw[p]*stop[v];
		kon[v]=konodw[p]*stop[v];
		poczodw[v]=poczodw[p]*(stop[v]-1);
		konodw[v]=konodw[p]*(stop[v]-1);
	}
	
	for(int i=0; i<tree[v].size(); i++)
	{
		if(tree[v][i]!=p)
		dfs(tree[v][i], v);
	}
}

long long wyn(int v)
{
	it1=mro.lower_bound(pocz[v]);
	it2=mro.lower_bound(kon[v]-1);
	st=mro.begin(); ed=mro.end();
	ed--;
	it3=it1;
	it3--;
	
//	cout<<*it1<<" "<<*it2<<"\n\n";
	
	if(pocz[v]>*ed||kon[v]-1<*st)
	return 0;
	if(*it2>=*it1)
	if(kon[v]<*it2&&pocz[v]>*it3)
	return 0;
	else
	return distance(it1,it2)+1;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>n>>g>>k;
	
	for(int i=0; i<g; i++)
	{
		cin>>m;
		mro.insert(m);
	}
	
	for(int i=0; i<n-1; i++)
	{
		cin>>a>>b;
		
		if(i==0)
		{
			st1=a; st2=b;
		}
		
		tree[a].push_back(b);
		tree[b].push_back(a);
		stop[a]++; stop[b]++;
	}
	
	pocz[st1]=stop[st1]*k;
	kon[st1]=stop[st1]*(k+1);
	poczodw[st1]=(stop[st1]-1)*k;
	konodw[st1]=(stop[st1]-1)*(k+1);
	pocz[st2]=stop[st2]*k;
	kon[st2]=stop[st2]*(k+1);
	poczodw[st2]=(stop[st2]-1)*k;
	konodw[st2]=(stop[st2]-1)*(k+1);
	
	dfs(st1, st2); dfs(st2, st1);
	
	for(int i=1; i<=n; i++)
	{
	//	cout<<pocz[i]<<" "<<kon[i]<<"\n";
		if(stop[i]==1)
		w+=wyn(i);
	}
	
	w*=k;
	
	cout<<w;
}
