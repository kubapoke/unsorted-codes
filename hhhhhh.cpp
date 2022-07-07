#include<iostream>
using namespace std;

//5 3 2 3 9 10 5 P 2 7 S P 3 4 P 1 10 S

int tab[1000001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i=0; i<1000001; i++)
	tab[i]=0;
	
	int n, q, a, b, x, y;
	long long s=0;
	char c;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>y;
		s+=y;
		tab[y]++;
	}
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>c;
		
		if(c=='S')
		cout<<s<<"\n";
		else if(c=='P')
		{
			cin>>a>>b;
			x=b-a;
			
			s+=x*tab[a];
			tab[b]+=tab[a];
			tab[a]=0;
			
		}
	}
	
	
}
