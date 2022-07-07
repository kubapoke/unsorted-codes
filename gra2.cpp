#include<bits/stdc++.h>
using namespace std;

int n, X, z, cv=1, k, platf[100001], d[2100001]/*, st[2100001]*/;
vector<pair<int,int> > G[2100001]; //nast?pnik, koszt
stack<int> PQ;
//priority_queue<pair<int,int> > PQ;
queue<pair<int,int> > dz[100001]; //pozycja, platforma

void postsort(int p)
{
	d[p]++;
	for(int i=0; i<G[p].size(); i++)
	{
		if(d[G[p][i].first]==0)
		postsort(G[p][i].first);
	}
	PQ.push(p);
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>X>>z;
	
	//PQ.push(make_pair(X+1,0));
	
	for(int cc=1; cc<=n; cc++)
	{
		cin>>k;
		platf[cc]=cv;
		for(int i=1; i<=k; i++)
		{
			int h;
			cin>>h;
			//PQ.push(make_pair(h,cv));
			dz[cc].push(make_pair(h,cv));
			if(platf[cc]!=cv)
			{
				G[cv].push_back(make_pair(cv-1,1));
				//st[cv-1]++;
			}
			while(!dz[cc-1].empty())
			{
				if(dz[cc-1].front().first<h)
				{
					G[cv].push_back(make_pair(dz[cc-1].front().second,0));
					//st[dz[cc-1].front().second]++;
					G[dz[cc-1].front().second+1].push_back(make_pair(cv,1));
					//st[cv]++;
					dz[cc-1].pop();
				}
				else
				break;
			}
			cv++;
		}
		//PQ.push(make_pair(X,cv));
		if(platf[cc]!=cv)
		{
			G[cv].push_back(make_pair(cv-1,1));
			//st[cv-1]++;
		}
		while(!dz[cc-1].empty())
		{
			G[cv].push_back(make_pair(dz[cc-1].front().second,0));
			//st[dz[cc-1].front().second]++;
			G[dz[cc-1].front().second+1].push_back(make_pair(cv,1));
			//st[cv]++;
			dz[cc-1].pop();
		}
		G[0].push_back(make_pair(cv,0));
		//st[cv]++;
		cv++;
	}
	
	postsort(0);
	
	d[0]=0;
	for(int i=1; i<=cv; i++)
	d[i]=2200000;

	while(!PQ.empty())
	{
		cout<<PQ.top()<<" ";
		for(int i=0; i<G[PQ.top()].size(); i++)
		{
			d[G[PQ.top()][i].first]=min(d[G[PQ.top()][i].first], d[PQ.top()]+G[PQ.top()][i].second);	
		}
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
