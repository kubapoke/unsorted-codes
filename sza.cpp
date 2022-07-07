#include<bits/stdc++.h>

using namespace std;

struct przedmioty{
	int c, a, b; //wartoœæ, moment w³o¿enia, moment wyjêcia
} item[1001];

struct zapytania{
	int m, k, s, idx; //czas startu, wartoœæ do uzyskania, czas trwania, index
} query[1000001];

bool comp1(const przedmioty &x, const przedmioty &y)
{
	return x.a<y.a;
}

bool comp2(const zapytania &x, const zapytania &y)
{
	return x.m<y.m;
}

int n, p, dp[100001], ans[1000001], INF=1e9;

void add(int i)
{
	int c=item[i].c, b=item[i].b;
	for(int i=100000; i>=c; i--)
	dp[i]=max(dp[i], min(dp[i-c], b));
}

void check(int j)
{
	if(dp[query[j].k]>query[j].m+query[j].s)
	ans[query[j].idx]=1;
	else
	ans[query[j].idx]=0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>item[i].c>>item[i].a>>item[i].b;
	}
	
	cin>>p;
	for(int i=1; i<=p; i++)
	{
		cin>>query[i].m>>query[i].k>>query[i].s;
		query[i].idx=i;
	}
	
	sort(item+1, item+n+1, comp1);
	sort(query+1, query+p+1, comp2);

	dp[0]=INF;
	int i=1, j=1;
	
	while(i<=n||j<=p)
	{
		if(j==p+1)
		break;
		if(i==n+1)
		{
			check(j);
			j++;
			continue;
		}
		if(item[i].a<=query[j].m)
		{
			add(i);
			i++;
		}
		else
		{
			check(j);
			j++;
		}
	}
	
	for(int i=1; i<=p; i++)
	if(ans[i]) cout<<"TAK\n";
	else cout<<"NIE\n";
}
