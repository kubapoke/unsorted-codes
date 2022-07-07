#include<iostream>
using namespace std;

int main()
{
	//5 3 4 3 2 4 1 2 1 3 5 1 4 1
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	register int N, R, K, a=0, b=0, c;
	
	cin>>N>>R>>K;
	
	int tab[N+1];
	int sec[N+1];
	int heh[R];
	
	for(int i=0; i<=N; i++)
	{
		tab[i]=i;
		sec[i]=i;
	}
	
	
	for(int i=0; i<R; i++)
	{
		cin>>b;
		
		heh[i]=b;	
	}
	
	for(int i=0; i<K; i++)
	{
		cin>>a>>b;
		
		if(tab[a]<tab[b])
		{
			c=tab[b];
			tab[b]=tab[a];
			tab[a]=c;
			
			//sec[tab[a]]=a;
			//sec[tab[b]]=b;
		}
	}
	
	for(int i=0; i<R; i++)
	{
		if(i!=0 && tab[heh[i]]<tab[heh[i-1]])
		{
			c=tab[heh[i]];
			tab[heh[i]]=tab[heh[i-1]];
			tab[heh[i-1]]=c;
			
			//sec[tab[heh[i]]]=tab[heh[i]];
			//sec[tab[heh[i-1]]]=tab[heh[i-1]];
		}	
		a=b;
	}
	
	for(int i=1; i<=N; i++)
	for(int j=1; j<=N; j++)
	if(tab[j]==i)
	{
		cout<<j<<" ";
		break;
	}
	
}
