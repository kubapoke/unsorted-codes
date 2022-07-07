#include<bits/stdc++.h>
using namespace std;

struct kraw{
	int a, b;
	bool odw;
};

int n, m, k, a, b, w;
const int INF=1e8;
int ans=INF;

vector<kraw> graf[30001];

bool czyprzezdwa(int i)
{
	if(i==1) return true;
	if(i%2!=0) return false;
	i/=2;
	return czyprzezdwa(i);
}

void gothru(int v, int sum, int pop)
{
	if(v==n)
	{
		ans=min(ans,sum);
		return;
	}
	
	for(int i=0; i<graf[v].size(); i++)
	{	
		if(graf[v][i].odw==false)
		{
			if(pop==0)
			{
				if(graf[v][i].b>=k)
				//cout<<"kek\n"<<graf[v][i].b<<" "<<k;
				{
					graf[v][i].odw=true;
					gothru(graf[v][i].a, sum+graf[v][i].b, graf[v][i].b);
					graf[v][i].odw=false;
				}
			}
			else 
			{
				int g=0;
				if(czyprzezdwa(max(pop,graf[v][i].b))==true)
				g=pop+graf[v][i].b;
				
				if(g>=k)
				{
					graf[v][i].odw=true;
					gothru(graf[v][i].a, sum+graf[v][i].b, graf[v][i].b);
					graf[v][i].odw=false;
				}
			}
		}
	}
	//cout<<"bruh\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>n>>m>>k;
	
	for(int i=1; i<=m; i++)
	{
		cin>>a>>b>>w;
		
		kraw kr;
		
		kr.a=b; kr.b=w; kr.odw=false;
		
		graf[a].push_back(kr);
	}
	
	gothru(1,0,0);
	
	if(ans==INF)
	cout<<"-1";
	else
	cout<<ans;
}
