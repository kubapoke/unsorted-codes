//Jakub P¹czka
#include<bits/stdc++.h>
using namespace std;

int n, k, ans, czyagent[500001];
vector<int> graf[500001];

 int get_ans_for_1(int v, int p, int d)
{
	int odp=d;
	
	for(auto u: graf[v])
	{
		if(u!=p)
		odp=max(odp, get_ans_for_1(u,v,d+1));
	}
	
	return odp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>k;
	
	for(int i=0; i<k; i++)
	{
		int x;
		cin>>x;
		czyagent[x]=1;
	}
	
	for(int i=0; i<n-1; i++)
	{
		int a, b;
		cin>>a>>b;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	
if(k==1)
{
	int A;
	ans=2*(n-k);
	
	for(int i=1; i<n; i++)
	if(czyagent[i]==1)
	{
		A=i;
		break;
	}
	
	ans-=get_ans_for_1(A,A,0);
	
	cout<<ans;
	
	return 0;
}
}
