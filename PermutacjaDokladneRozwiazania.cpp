#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n=10;
vector<vector<int>> tab[1000000];
vector<int> pom;
map<ll,map<ll,ll>> mapa;
map<ll,ll>::iterator x;

ll rozwiazanie(vector<int> &v)
{
	bool unsorted=false;
	int pos, ser, temp;
	ll cost=0;
	
	while(1)
	{
		if(v[0]==1)
		ser=v.size();
		else
		ser=v[0]-1;
		
		unsorted=false;
		for(int i=0; i<v.size(); i++)
		{
			if(i!=0)
			if(v[i]!=v[i-1]+1)
			unsorted=true;
			
			if(v[i]==ser)
			pos=i;
		}
		
		if(unsorted==false)
		{
			mapa[v.size()][cost]++;
			return cost;
		}
		
		else
		{
			temp=v[pos];
			cost+=pos;
			for(int i=pos; i>0; i--)
			{
				v[i]=v[i-1];
			}
			v[0]=temp;
		}
	}
}

int main()
{
	pom.push_back(1);
	tab[1].push_back(pom);
	pom.clear();
	
	cout<<"ta liczba - pojawia sie tyle razy\n\n";
	
	for(ll i=2; i<=n; i++)
	{
		for(ll j=0; j<tab[i-1].size(); j++)
		{
			for(ll c=0; c<i; c++)
			{
				pom=tab[i-1][j];
				pom.insert(pom.begin()+c,i);
				tab[i].push_back(pom);
			}
		}
	}
	
	for(ll i=1; i<=n; i++)
	{
		ll w=0;
		for(ll j=0; j<tab[i].size(); j++)
		{
			w+=rozwiazanie(tab[i][j]);
		}
		cout<<i<<": "<<w<<"\n";
		for(x=mapa[i].begin(); x!=mapa[i].end(); x++)
		cout<<x->first<<"-"<<x->second<<" ";
		cout<<"\n\n";
	}
}
