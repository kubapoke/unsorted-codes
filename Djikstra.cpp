#include<bits/stdc++.h>
#define N 1000001
using namespace std;

/* Przyk³adowy test 
8 8 1
1 2 1
2 3 4
1 3 6
1 5 2
5 6 2
6 1 3
6 7 8
8 7 4
*/

int V, E, d[N], popr[N], vis[N], a, b, k, INF=1e9, pocz; //iloœæ wierzcho³ków / krawêdzi / d³ugoœci dróg / poprzednik w najkrótszej drodze / odwiedzone / tymczasowe zmienne / nieskoñczonoœæ / wierzcho³ek startowy
vector<int> kolej;             //kolejka prioretytowa
vector< pair<int, int> > G[N]; //nastêpnik i waga przejœcia

void postorder(int p)
{
	vis[p]++;
	
	for(int i=0; i<G[p].size(); i++)
	{
		if(vis[G[p][i].first]==0)
		postorder(G[p][i].first);
	}
	
	kolej.push_back(p);
}

void droga(int i)
{
	if(i!=pocz)
	droga(popr[i]);
	
	cout<<i<<" ";
}

int main()
{
	
	cin>>V>>E>>pocz;
	
	for(int i=1; i<=E; i++)
	{
		cin>>a>>b>>k;
		G[a].push_back({b,k});
	}
	
	d[1]=0;
	
	for(int i=1; i<=V; i++)
	d[i]=INF;
	
	d[pocz]=0;
		
	postorder(pocz);
	
	for(int i=kolej.size()-1; i>=0; i--)
	{
		int kol=kolej[i];
		
		for(int j=0; j<G[kol].size(); j++)
		{
			if(d[G[kol][j].first]>d[kol]+G[kol][j].second)
			{
				d[G[kol][j].first]=d[kol]+G[kol][j].second;
				popr[G[kol][j].first]=kol;
			}
		}
	}
	
	for(int i=1; i<=V; i++)
	{
		if(d[i]==INF)
		cout<<i<<": INF\n";
		else
		{
			cout<<i<<": "<<d[i]<<"    droga: ";
			droga(i);
			cout<<"\n";
		}
		
	}
	
}
