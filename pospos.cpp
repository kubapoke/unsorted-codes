#include<bits/stdc++.h>
#define INF 1e9
using namespace std;

/*
6
1 5 7
1 2 2
2 3 8
2 4 3
4 6 2
*/

struct kraw{
	int f, s, w;//s¹siad / d³ugoœæ / wartoœæ
};

struct kolejnosc{
	int wart, idx;
};

bool compare1(const kolejnosc &x, const kolejnosc &y)
{
	return x.wart<y.wart;
}

int n, a, b, t, vis[100001], pop[100001], wart[100001], mwart[100001], pp[100001], maks, idx, gog[100001];
float w;
kraw kr;
vector<kraw> graf[100001];
vector<kolejnosc> kol[100001];
vector<int> kolej;
//vector<pair<int,int> > graf[10001];

void gothru(int v, int p, int val, int popplus)
{
	pop[v]=p;
	wart[v]=val;
	pp[v]=popplus;
	maks=max(maks,val);
	if(maks==val)
	idx=v;
	
	for(int i=0; i<graf[v].size(); i++)
	{
		if(pop[v]!=graf[v][i].f)
		gothru(graf[v][i].f,v,val+graf[v][i].s,graf[v][i].s);
	}
	
	kolej.push_back(v);
}

int gothru2(int v, int val)
{
	
	if(vis[v]==0)
	{
		w+=(float)val;
		vis[v]++;
		//cout<<"!";
	}
	
	
	//cout<<val<<"  ";
	
	//cout<<v<<"\n";
	
	if(v==idx)
	return val;
	
	if(kol[v].empty())
	{
		for(int i=0; i<graf[v].size(); i++)
		{
			if(pop[v]!=graf[v][i].f&&vis[graf[v][i].f]==0)
			{
				kolejnosc k;
				k.wart=mwart[graf[v][i].f]; k.idx=graf[v][i].f;
				kol[v].push_back(k);
			}
		}
		
		sort(kol[v].begin(), kol[v].end(), compare1);
	}
	
	for(int i=gog[v]; i<kol[v].size(); i++)
	{
		gog[v]++;
		return gothru2(kol[v][i].idx, val+pp[kol[v][i].idx]);
	}
	
	return gothru2(pop[v],val+pp[v]);
}

int main()
{
	cin>>n;
	
	for(int i=1; i<=n-1; i++)
	{
		cin>>a>>b>>t;
		kr.f=b; kr.s=t; kr.w=INF;
		graf[a].push_back(kr);
		kr.f=a;
		graf[b].push_back(kr);
		//w+=(float)2*t;
		
		//cout<<graf[a][0].f<<" "<<graf[a][0].s<<" "<<graf[a][0].w<<" ";
	}
	
	gothru(1,0,0,0);
	
	//cout<<idx<<"\n";
	
	for(int i=0; i<kolej.size(); i++)
	{
		int temp=wart[kolej[i]];
		for(int j=0; j<graf[kolej[i]].size(); j++)
		{
			if(pop[kolej[i]]!=graf[kolej[i]][j].f)
			temp=max(temp,mwart[graf[kolej[i]][j].f]);
		}
		mwart[kolej[i]]=temp;
	}
	
	gothru2(1,0);
	
	w/=(float)(n-1);
	
	cout<<fixed<<setprecision(6)<<w;
	
	
	/*
	for(int i=1; i<=n; i++)
	cout<<mwart[i]<<"  ";
	*/
	/*
	w-=(float)maks;
	
	cout<<fixed<<setprecision(6)<<w;
	*/
}
