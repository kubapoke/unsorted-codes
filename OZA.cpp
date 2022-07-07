#include<bits/stdc++.h>
using namespace std;

long long w, wart[100005];
int n, k, stan[100005];
priority_queue<pair<long long,int>> PQ;

int main()
{
	cin>>n>>k;
	
	for(int i=1; i<=n; i++)	
	cin>>wart[i];
	
	for(int i=1; i<=n; i++)	
	{
		cin>>stan[i];
		if(stan[i]==1)
		PQ.push({-wart[i],i});
	}
	
	for(int i=0; i<k; i++)
	{
		w+=-PQ.top().first;
		
		if(PQ.top().second!=1 && stan[PQ.top().second-1]==0)
		{
			stan[PQ.top().second-1]=1;
			wart[PQ.top().second-1]+=wart[PQ.top().second];
			PQ.push({-wart[PQ.top().second-1],PQ.top().second-1});
		}
		
		if(PQ.top().second!=n && stan[PQ.top().second+1]==0)
		{
			stan[PQ.top().second+1]=1;
			wart[PQ.top().second+1]+=wart[PQ.top().second];
			PQ.push({-wart[PQ.top().second+1],PQ.top().second+1});
		}
		
		PQ.pop();
	}
	
	cout<<w;
}
