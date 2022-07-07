#include<bits/stdc++.h>
using namespace std;

int tab[1501][1501], sumpref[1501];
int n, m, k;
long long ans, odm;
stack<pair<int,int>> S; //para<g³êbokoœæ, indeks pocz¹tkowy>

void wypisz() //funkcja do testowania
{
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		cout<<tab[i][j]<<" ";
		cout<<"\n";
	}
}

void addans(int idx)
{	
int q=ans;
	int i=S.top().first, j=S.top().second, x=0, y=0;
	
	S.pop();
	
	if(!S.empty())
	{
		x=S.top().first; y=S.top().second;
	}
	
	ans+=(i-x)*(idx-j);
cout<<ans-q<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m>>k; //wczytywanie danych
	
	for(int i=0; i<k; i++)
	{
		int a, b;
		cin>>a>>b;
		tab[a][b]=-1;
	}
	
	for(int i=1; i<=max(n,m); i++) //tworzymy sumy prefiksowe
	sumpref[i]=i+sumpref[i-1];
	
	for(int j=m; j>0; j--) //ustalanie glebokosci
	{
		int gl=0;
		for(int i=n; i>0; i--)
		{
			if(tab[i][j]==-1)
			gl=0;
			else
			gl++;
			
			if(gl>0)
			tab[i][j]=gl;
		}	
	}
	
	for(int i=1; i<=n; i++)
	{
		int idx;
		odm=0;
		for(int j=1; j<=m; j++)
		{
			if(tab[i][j]!=-1)
			{
				if(S.empty() || S.top().first<tab[i][j])
				S.push({tab[i][j], j});
				else while(!S.empty() && S.top().first>tab[i][j])
				{
					idx=S.top().second;
					cout<<i<<" "<<j<<" "<<S.top().first<<" ";
					addans(j);
				}
				
				if(S.empty() || S.top().first<tab[i][j])
				S.push({tab[i][j], idx});
			}
			else
			{
				while(!S.empty())
				{
					cout<<i<<" "<<j<<" "<<S.top().first<<" ";
					addans(j);
				}
			}
			
			if(j==m)
			{
				while(!S.empty())
				{
					cout<<i<<" "<<j<<" "<<S.top().first<<" ";
					addans(j+1);
				}
			}
		}
	}
	
	//wypisz();
	
	cout<<ans;
}
