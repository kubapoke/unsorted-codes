#include<bits/stdc++.h>
using namespace std;

int n, X, z, cv=1, k, platf[100001], d[2100001];
vector<int> G[2100001];
vector<pair<int,int> > GR[2100001]; //nastêpnik, koszt
stack<int> PQ;
queue<pair<int,int> > dz[100001]; //pozycja, platforma

void postsort(int p)
{
	d[p]++;
	for(int i=0; i<G[p].size(); i++)
	{
		if(d[G[p][i]]==0)
		postsort(G[p][i]);
	}
	PQ.push(p);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>X>>z;
	
	for(int cc=1; cc<=n; cc++)
	{
		cin>>k;
		platf[cc]=cv;
		for(int i=1; i<=k; i++)
		{
			int h;
			cin>>h;
			dz[cc].push(make_pair(h,cv));
			if(platf[cc]!=cv)
			{
				G[cv].push_back(cv-1);
				GR[cv-1].push_back(make_pair(cv,1));
			}
			while(!dz[cc-1].empty())
			{
				if(dz[cc-1].front().first<h)
				{
					G[cv].push_back(dz[cc-1].front().second);
					GR[dz[cc-1].front().second].push_back(make_pair(cv,0));
					G[dz[cc-1].front().second+1].push_back(cv);
					GR[cv].push_back(make_pair(dz[cc-1].front().second+1,1));
					dz[cc-1].pop();
				}
				else
				break;
			}
			cv++;
		}
		if(platf[cc]!=cv)
		{
			G[cv].push_back(cv-1);
			GR[cv-1].push_back(make_pair(cv,1));
		}
		while(!dz[cc-1].empty())
		{
			G[cv].push_back(dz[cc-1].front().second);
			GR[dz[cc-1].front().second].push_back(make_pair(cv,0));
			G[dz[cc-1].front().second+1].push_back(cv);
			GR[cv].push_back(make_pair(dz[cc-1].front().second+1,1));
			dz[cc-1].pop();
		}
		G[0].push_back(cv);
		GR[cv].push_back(make_pair(0,0));
		cv++;
	}
	
	postsort(0);
	
	d[0]=0;
	for(int i=1; i<=cv; i++)
	d[i]=1000000001;

	while(!PQ.empty())
	{
		//cout<<PQ.top()<<"\n";
		for(int i=0; i<GR[PQ.top()].size(); i++)
		{
			d[PQ.top()]=min(d[PQ.top()], d[GR[PQ.top()][i].first]+GR[PQ.top()][i].second);
			//cout<<d[GR[PQ.top()][i].first]+GR[PQ.top()][i].second<<" ";
		}
		//cout<<"\n\n";
		PQ.pop();
	}
	/*
	for(int i=1; i<cv; i++)
	cout<<d[i]<<" ";
	cout<<"\n";
	for(int i=0; i<GR[14].size(); i++)
	cout<<GR[11][i].second<<" ";
	cout<<d[11];
	*/
	
	for(int i=0; i<z; i++)
	{
		int x;
		cin>>x;
		cout<<d[platf[x]]<<"\n";
	}
	
}
