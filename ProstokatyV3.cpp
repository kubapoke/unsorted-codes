#include<bits/stdc++.h>
using namespace std;

int tab[1501][1501];
int n, m, k;
long long ans, g=0, pans;
stack<pair<int,int>> S; //para<g??boko??, indeks pocz?tkowy>

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
		for(int j=1; j<=m; j++)
		{
			int qq=ans;
			cout<<i<<" "<<j<<" ";
			
			if(tab[i][j]!=-1)
			{
				if(S.empty() || tab[i][j]>S.top().first)
				{
					S.push({tab[i][j], j});
				}
				else while(!S.empty() && tab[i][j]<S.top().first)
				{
					idx=S.top().second;
					S.pop();
				}
				if(S.empty() || tab[i][j]>S.top().first)
				{
					S.push({tab[i][j], idx});
				}
				
				ans+=(j-S.top().second+1)*(tab[i][j]);
				if(j!=m && tab[i][j+1]>tab[i][j])
				ans+=(j-S.top().second+1)*(tab[i][j]);
			}
			else
			{
				while(!S.empty())
				{
					S.pop();
				}
			}
			
			if(j==m)
			{
				while(!S.empty())
				{
					S.pop();
				}
			}
			
			cout<<ans-qq<<"\n";
		}
	}
	
	cout<<ans;
}
