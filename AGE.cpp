//Jakub P¹czka
#include<bits/stdc++.h>
using namespace std;

int n, k, czyagent[500001], ans;
vector<int> graf[500001], agent;
priority_queue<pair<int,int>> PQ;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>k;
	
	ans=2*(n-k);
	
	for(int i=0; i<k; i++)
	{
		int x;
		cin>>x;
		agent.push_back(x);
		czyagent[x]=1;
	}
	
	for(int i=0; i<n-1; i++)
	{
		int a, b;
		cin>>a>>b;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	
	
	cout<<ans;
	
}
